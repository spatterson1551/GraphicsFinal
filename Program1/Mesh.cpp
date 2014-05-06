#include "Mesh.h"


Mesh::Mesh(void)
{
	type = 'm';
}
//
//Mesh::Mesh(unsigned int vLocation_position, unsigned int vLocation_norm)
//{
//	Mesh::vLocation_position = vLocation_position;
//	Mesh::vLocation_norm = vLocation_norm;
//}
Mesh::Mesh(std::string fileName, unsigned int vLocation_position, unsigned int vLocation_norm) {

	create(vLocation_position, vLocation_norm, fileName);
	type = 'm';
}

Mesh::~Mesh(void)
{

}

void Mesh::create(unsigned int vLocation_position, unsigned int vLocation_norm, std::string file) {

	std::ifstream fin;
	fin.open(file);

	std::string type;
	fin >> type;

	Mesh::vLocation_position = vLocation_position;
	Mesh::vLocation_norm = vLocation_norm;

	if(type == "extrusion") 
		buildExtrusion(vLocation_position, vLocation_norm, fin);
	else if (type == "surfrev") {
		buildSurfRev(vLocation_position, vLocation_norm, fin);
	}
}

void Mesh::buildExtrusion(unsigned int vLocation_position, unsigned int vLocation_norm, std::ifstream& fin) {
	
	int numPts; 
	fin >> height >> numPts;
	numPts-=1;

	//create the base
	for (int i = 0; i < numPts; i++) {
		float x, z;
		fin >> x;
		fin >> z;
		basePts.push_back(Point(x, 0, z));
	}
	fin.close();

	//create the top projection of the base
	for (int i = 0; i < basePts.size(); i++) {
		topPts.push_back(Point(basePts[i].x, basePts[i].y+height, basePts[i].z));
	}

	//triangulate end caps only if the shape is convex
	if(isConvex(basePts, numPts)) {

		for (int i = 1; i < basePts.size()-1; i++) {
			faceList.push_back(Face(basePts[0], basePts[i], basePts[i+1]));
		}
		int limit = faceList.size();
		for (int i = 0; i < limit; i++) {
			Face temp;
			temp = faceList[i];
			temp.pt1.y += height;
			temp.pt2.y += height;
			temp.pt3.y += height;
			faceList.push_back(temp);
		}
	}

	//build walls
	for(int i = 0; i < basePts.size(); i++) {
		faceList.push_back(Face(basePts[i], basePts[(i+1)%basePts.size()], topPts[(i+1)%basePts.size()]));
		faceList.push_back(Face(basePts[i], topPts[(i+1)%basePts.size()], topPts[i]));
	}

	constructHalfEdge();
	setPtsAndNormals();
	setBuffers(vLocation_position, vLocation_norm);

}

void Mesh::buildSurfRev(unsigned int vLocation_position, unsigned int vLocation_norm, std::ifstream& fin) {
	
	int numPts;
	int pieces; 
	fin >> pieces;
	fin >> numPts;

	//get points
	for(int i = 0; i<numPts; i++) {
		float x, y;
		fin >> x; 
		fin >> y;
		basePts.push_back(Point(x, y, 0));
	}
	height = basePts[basePts.size()-1].y+1;

	//if pts dont lie on y axis
	if(basePts[0].x != 0.0f) {
		basePts.insert(basePts.begin(), Point(0, basePts[0].y, basePts[0].z));
	}

	if(basePts[basePts.size()-1].x != 0.0f) {
		basePts.push_back(Point(0, basePts[basePts.size()-1].y, basePts[basePts.size()-1].z));
	}

	float rot = 360.0f/pieces;
	glm::mat4 matrix(1.0f);
	matrix = glm::rotate(matrix, rot, glm::vec3(0.0f, 1.0f, 0.0f));

	std::vector<Point> oldPts;
	std::vector<Point> newPts;
	for(int i = 0; i < basePts.size(); i++) {
		oldPts.push_back(basePts[i]);
	}
	newPts.resize(basePts.size());
	for(int i = 0; i < newPts.size(); i++) {
		newPts[i] = Point(0, 0, 0);
	}

	for(int j = 0; j < pieces; j++)
	{
		//calculate the points for the rotated piece
		for(int i = 0; i < basePts.size(); i++) {
			glm::vec4 temp = matrix * glm::vec4(oldPts[i].x, oldPts[i].y, oldPts[i].z, 1.0f);
			newPts[i].x = temp.x;
			newPts[i].y = temp.y;
			newPts[i].z = temp.z;
		}

		//triangulate
		for(int i = 0; i < basePts.size()-1; i++) {
			faceList.push_back(Face(oldPts[i], newPts[i], oldPts[i+1]));
			faceList.push_back(Face(newPts[i], newPts[i+1], oldPts[i+1]));
		}

		for(int i = 0; i < basePts.size(); i++) {
			oldPts[i] = newPts[i];
		}
	}

	constructHalfEdge();
	setPtsAndNormals();
	setBuffers(vLocation_position, vLocation_norm);
}

void Mesh::constructHalfEdge() {

	for (int i = 0; i < faceList.size(); i++) {
		
		int pt1i = vertExists(faceList[i].pt1);
		if (pt1i == -1) {
			verts.push_back(new Vertex(faceList[i].pt1, NULL));
			pt1i = verts.size()-1;
		}
		int pt2i = vertExists(faceList[i].pt2);
		if (pt2i == -1) {
			verts.push_back(new Vertex(faceList[i].pt2, NULL));
			pt2i = verts.size()-1;
		}
		int pt3i = vertExists(faceList[i].pt3);
		if (pt3i == -1) {
			verts.push_back(new Vertex(faceList[i].pt3, NULL));
			pt3i = verts.size()-1;
		}
	
		glm::vec3 vec1(faceList[i].pt2.x - faceList[i].pt1.x, faceList[i].pt2.y - faceList[i].pt1.y, faceList[i].pt2.z - faceList[i].pt1.z);
		glm::vec3 vec2(faceList[i].pt3.x - faceList[i].pt1.x, faceList[i].pt3.y - faceList[i].pt1.y, faceList[i].pt3.z - faceList[i].pt1.z);
		glm::vec3 normal = glm::normalize(glm::cross(vec1, vec2));
	
		faces.push_back(new HEFace(NULL, normal));
		edges.push_back(new Edge(faces[faces.size()-1], NULL, NULL, verts[pt2i], verts[pt1i]->pt));
		edges.push_back(new Edge(faces[faces.size()-1], NULL, NULL, verts[pt3i], verts[pt2i]->pt));
		edges.push_back(new Edge(faces[faces.size()-1], NULL, NULL, verts[pt1i], verts[pt3i]->pt));
		edges[edges.size()-3]->next = edges[edges.size()-2];
		edges[edges.size()-2]->next = edges[edges.size()-1];
		edges[edges.size()-1]->next = edges[edges.size()-3];
		faces[faces.size()-1]->edge = edges[edges.size()-3];
		if (verts[pt1i]->edge == NULL) {
			verts[pt1i]->edge = edges[edges.size()-3];
		}
		if (verts[pt2i]->edge == NULL) {
			verts[pt2i]->edge = edges[edges.size()-2];
		}
		if (verts[pt3i]->edge == NULL) {
			verts[pt3i]->edge = edges[edges.size()-1];
		}
		int e1i = edgeExists(faceList[i].pt2, faceList[i].pt1);
		if (e1i != -1) {
			edges[edges.size()-3] = edges[e1i];
			edges[e1i] = edges[edges.size()-3];
		}
		int e2i = edgeExists(faceList[i].pt3, faceList[i].pt2);
		if (e2i != -1) {
			edges[edges.size()-2] = edges[e2i];
			edges[e2i] = edges[edges.size()-2];
		}
		int e3i = edgeExists(faceList[i].pt1, faceList[i].pt3);
		if (e3i != -1) {
			edges[edges.size()-1] = edges[e3i];
			edges[e3i] = edges[edges.size()-1];
		}
	}
}

void Mesh::setPtsAndNormals() {

	for (int i = 0; i < faces.size(); i++) {
		pts.push_back(glm::vec4(faces[i]->edge->vert->pt.x, faces[i]->edge->vert->pt.y, faces[i]->edge->vert->pt.z, 1.0f));
		pts.push_back(glm::vec4(faces[i]->edge->next->vert->pt.x, faces[i]->edge->next->vert->pt.y, faces[i]->edge->next->vert->pt.z, 1.0f));
		pts.push_back(glm::vec4(faces[i]->edge->next->next->vert->pt.x, faces[i]->edge->next->next->vert->pt.y, faces[i]->edge->next->next->vert->pt.z, 1.0f));

		for (int i = 0; i < 3; i++) {
			ptNormals.push_back(faces[i]->normal);
		}
	}
}

void Mesh::setBuffers(unsigned int vLocation_position, unsigned int vLocation_norm) {

	glGenBuffers(1, &vbo);   
	glGenBuffers(1, &vbo_normal);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, pts.size() * sizeof(glm::vec4), pts.data(), GL_STATIC_DRAW); //actually sends/connects the buffer to GPU
	glEnableVertexAttribArray(vLocation_position); 
	glVertexAttribPointer(vLocation_position, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_normal);
	glBufferData(GL_ARRAY_BUFFER, ptNormals.size() * sizeof(glm::vec3), ptNormals.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(vLocation_norm);
	glVertexAttribPointer(vLocation_norm, 3, GL_FLOAT, GL_FALSE, 0,0);
}

bool Mesh::isConvex(std::vector<Point> points, int numPts) {
	
	if(points.size() <= 3)  {
		return true; //triangle so automatically convex
	}

	glm::vec3 vec1(points[1].x - points[0].x, 0, points[1].z - points[0].z);
	glm::vec3 vec2(points[numPts - 1].x - points[0].x, 0, points[numPts - 1].z - points[0].z);
	glm::vec3 normal;
	normal = glm::cross(vec1, vec2);

	for(int i = 1; i < numPts; i++)
	{
		glm::vec3 t;
		glm::vec3 vec1(points[(i+1) % points.size()].x - points[i].x, 0, points[(i+1) % points.size()].z - points[i].z);
		glm::vec3 vec2(points[i-1].x - points[i].x, 0, points[i-1].z - points[i].z);
		t = glm::cross(vec1, vec2);
		if (glm::normalize(t) == glm::normalize(-normal)) {
			return false;
		}
	}

	return true;
}

int Mesh::getFaceIndex(HEFace* f) {
	for (int i = 0; i < faces.size(); i++) {
		if (faces[i] == f) {
			return i;
		}
	}
	return -1;
}

void Mesh::catmullClark() {

	//calculate centroids
	for (int i = 0; i < faces.size(); i++) {
		Edge* original = faces[i]->edge;
		Edge* current = faces[i]->edge;
		int count = 1;
		float x = current->vert->pt.x;
		float y = current->vert->pt.y;
		float z = current->vert->pt.z;
		while (current->next != original) {
			count++;
			current = current->next;
			x += current->vert->pt.x;
			y += current->vert->pt.y;
			z += current->vert->pt.z;
		}
		centroids.push_back(Point(x/count, y/count, z/count));
	}
	//divide up the half edges
	int limit = edges.size();
	for (int i = 0; i < limit; i++) {
		//assume face indices is j and k
		int j = getFaceIndex(edges[i]->face);
		int k = getFaceIndex(edges[i]->pair->face);
		Point p;
		p.x = (edges[i]->extFrom.x + edges[i]->vert->pt.x + centroids[j].x + centroids[k].x)/4.0f;
		p.y = (edges[i]->extFrom.y + edges[i]->vert->pt.y + centroids[j].y + centroids[k].y)/4.0f;
		p.z = (edges[i]->extFrom.z + edges[i]->vert->pt.z + centroids[j].z + centroids[k].z)/4.0f;
		//break up the existing 2 half edges, create 2 new half edges
		int e1i = edgeExists(edges[i]->extFrom, edges[i]->vert->pt);
		int v1i = vertExists(p);
		if (v1i == -1) { //doesnt exist
			verts.push_back(new Vertex(p, NULL)); //shouldnt do if already created
			v1i = verts.size()-1;
		}
		edges.push_back(new Edge(NULL, edges[i]->next, NULL, edges[i]->vert, p));
		edges[i]->vert = verts[v1i];
		edges[i]->face = NULL;
		edges[i]->pair = NULL;
		//edges[i]->next = edges[edges.size()-1];
		if (verts[v1i]->edge == NULL) {
			verts[v1i]->edge = edges[edges.size()-1]; //shouldnt do if already created
		}
		int v2i = vertExists(centroids[j]);
		if (v2i == -1) { //doesnt exist
			verts.push_back(new Vertex(p, NULL));
			v2i = verts.size()-1;
		}
		edges.push_back(new Edge(NULL, NULL, NULL, verts[v2i], p));
		edges.push_back(new Edge(NULL, NULL, NULL, verts[v1i], verts[v2i]->pt));
		edges[edges.size()-1]->pair = edges[edges.size()-2];
		edges[edges.size()-2]->pair = edges[edges.size()-1];
		if (verts[v2i]->edge == NULL) {
			verts[v2i]->edge = edges[edges.size()-1];
		}
		edges[i]->next = edges[edges.size()-2];
		edges[edges.size()-1]->next = edges[edges.size()-3];
	}
	//set up pairs
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->pair == NULL) {
			int ei = edgeExists(edges[i]->vert->pt, edges[i]->extFrom);
			edges[i]->pair = edges[ei];
			edges[ei]->pair = edges[i];
		}
	}
	//finish setting the next's
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->next == NULL) {
			for (int j = 0; j < edges.size(); j++) {
				if (edges[j]->extFrom == edges[j]->pair->vert->pt) {
					edges[i]->next = edges[j];
				}
			}
		}
	}
	//create all of the new faces
	for (int i = 0; i < faces.size(); i++) {
		delete faces[i];
	}
	faces.clear();
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->face == NULL) {
			Edge* original = edges[i];
			Edge* e = edges[i];
			faces.push_back(new HEFace(edges[i], glm::vec3(0, 0, 0)));
			while (e != original) {
				if (e->face == NULL) {
					e->face = faces[faces.size()-1];
				}
				e = e->next;
			}
		}
	}
	int i = 0;
	i++;
	setPtsAndNormals();

}

void Mesh::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {

	//glm::mat4 tr = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	//glm::mat4 sc = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 4.0f, 2.0f));
	//glm::mat4 ro = glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	//m = m * tr * ro * sc;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position); 
	glVertexAttribPointer(vLocation_position, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_normal);

	glm::vec3 color(0,1,0);
	glUniform3fv(u_colorLocation, 1, &color[0]);
	glUniformMatrix4fv(u_modelLocation, 1, GL_FALSE, &m[0][0]);
	glEnableVertexAttribArray(vLocation_norm);
	glVertexAttribPointer(vLocation_norm, 3, GL_FLOAT, GL_FALSE, 0,0);

	glDrawArrays(GL_TRIANGLES, 0, pts.size());
}

void Mesh::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation, glm::vec3 color) {

	//glm::mat4 tr = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	//glm::mat4 sc = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 4.0f, 2.0f));
	//glm::mat4 ro = glm::rotate(glm::mat4(1.0f), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	//m = m * tr * ro * sc;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position); 
	glVertexAttribPointer(vLocation_position, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_normal);

	glUniform3fv(u_colorLocation, 1, &color[0]);
	glUniformMatrix4fv(u_modelLocation, 1, GL_FALSE, &m[0][0]);
	glEnableVertexAttribArray(vLocation_norm);
	glVertexAttribPointer(vLocation_norm, 3, GL_FLOAT, GL_FALSE, 0,0);

	glDrawArrays(GL_TRIANGLES, 0, pts.size());
}


int Mesh::vertExists (Point p) {
		for (int i = 0; i < verts.size(); i++) {
			if (verts[i]->pt.x == p.x && verts[i]->pt.y == p.y && verts[i]->pt.z == p.z)
				return i;
		}
		return -1;
	}

int Mesh::edgeExists (Point p1, Point p2) {

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i]->extFrom.x == p1.x && edges[i]->extFrom.y == p1.y && edges[i]->extFrom.z == p1.z) {
			if (edges[i]->vert->pt.x == p2.x && edges[i]->vert->pt.y == p2.y && edges[i]->vert->pt.z == p2.z) {
				return i;
			}
		}
	}
	return -1;
}