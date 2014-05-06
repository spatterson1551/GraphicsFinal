#include "sceneGraph.h"


SceneGraph::SceneGraph(int width, int depth)
{
	children = new SceneGraph*[width*depth];

	for (int i = 0; i < width*depth; i++) {
		children[i] = NULL;
	}

	geom = NULL;

}

SceneGraph::SceneGraph() {

	children = new SceneGraph*[1]; 
	children[0] = NULL;
	geom = NULL;
}

SceneGraph::~SceneGraph() {

}

void SceneGraph::addChild(SceneGraph* sg, int idx_x, int idx_z) {


	if(geom) {						
		//sg->setTransY(geom->getHeight());
		//sg->transY = 0.0f;
		sg->transY = geom->height;
	}
	if(children[idx_x * depth + idx_z]) {
		children[idx_x * depth + idx_z]->addChild(sg, 0, 0);
	}
	else {
		//sg->setTransX(idx_x + 0.5f);
 		//sg->setTransZ(idx_z + 0.5f);
		sg->transX = idx_x;// + 0.05f;
		sg->transZ = idx_z;// + 0.05f;
		//children[idx_x * depth + idx_z] = sg;
		children[idx_x * depth + idx_z] = new SceneGraph(1, 1);
		children[idx_x * depth + idx_z]->depth = 1;
		children[idx_x * depth + idx_z]->width = 1;
		children[idx_x * depth + idx_z]->rotY = sg->rotY;
		children[idx_x * depth + idx_z]->scaleX = sg->scaleX;
		children[idx_x * depth + idx_z]->scaleY = sg->scaleY;
		children[idx_x * depth + idx_z]->scaleZ = sg->scaleZ;
		children[idx_x * depth + idx_z]->transX = sg->transX - width/2;
		children[idx_x * depth + idx_z]->transY = sg->transY;
		children[idx_x * depth + idx_z]->transZ = sg->transZ - depth/2;
		children[idx_x * depth + idx_z]->geom = sg->geom;
	}
}

void SceneGraph::traverse(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation, int whichNode, int currentNode, Transformations t, bool divide) {

	if (currentNode == whichNode) {
		transX += t.deltaX;
		transZ += t.deltaZ;
		transY += t.deltaY;
		rotY += t.rotY;
		scaleX += t.scaleX;
		scaleY += t.scaleY;
		scaleZ += t.scaleZ;
		if ((divide == true) && (geom->type == 'm')) {
			geom->catmullClark();
			transX += 3.0f;
		}
	}

	glm::mat4 tr = glm::translate(glm::mat4(1.0f), vec3(transX, transY, transZ));
	glm::mat4 sc = glm::scale(glm::mat4(1.0f), vec3(scaleX, scaleY, scaleZ));
	glm::mat4 ro = glm::rotate(glm::mat4(1.0f), rotY, vec3(0.0f, 1.0f, 0.0f));

	m = m * tr * ro * sc;

	if(geom) {
		geom->draw(m, u_modelLocation, u_colorLocation);
	}

	for(int i = 0; i < width * depth; i++) {
		if(children[i]) {
			children[i]->traverse(m, u_modelLocation, u_colorLocation, whichNode, currentNode+1, t, divide);
		}
	}
}

