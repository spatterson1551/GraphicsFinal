#pragma once
#define GLEW_STATIC
#include "glew.h"
#include <QGLWidget>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <QDebug>
#include <vector>
#include <string>
#include <fstream>
#include "Point.h"
#include "Vertex.h"
#include "Edge.h"
#include "HEFace.h"
#include "Geometry.h"
#include <utility>

struct Face {
	glm::vec3 normal;
	Point pt1, pt2, pt3;
	Face::Face() {
		pt1 = Point(0, 0, 0);
		pt2 = Point(0, 0, 0);
		pt3 = Point(0, 0, 0);
		normal = glm::vec3(0, 0, 0);
	}
	Face::Face(Point p1, Point p2, Point p3) {
		pt1 = p1;
		pt2 = p2;
		pt3 = p3;
		normal = glm::vec3(0, 0, 0);
	}
};


class Mesh : public Geometry
{
public:
	Mesh(void);
	//Mesh(unsigned int, unsigned int);
	Mesh(std::string, unsigned int, unsigned int);
	void create(unsigned int, unsigned int, std::string);
	void buildExtrusion(unsigned int, unsigned int, std::ifstream&);
	void buildSurfRev(unsigned int, unsigned int, std::ifstream&);
	void constructHalfEdge();
	void setPtsAndNormals();
	void setBuffers(unsigned int, unsigned int);

	int vertExists (Point p);
	int edgeExists (Point p1, Point p2);

	bool isConvex(std::vector<Point>, int);
	void draw(glm::mat4, unsigned int, unsigned int);
	void draw(glm::mat4, unsigned int, unsigned int, glm::vec3);

	~Mesh(void);

private:
	std::vector<Face> faceList;
	std::vector<HEFace*> faces;
	std::vector<Edge*> edges;
	std::vector<Vertex*> verts;
	std::vector<glm::vec3> ptNormals;
	std::vector<Point> basePts;
	std::vector<Point> topPts;
	std::vector<glm::vec4> pts;


	unsigned int vLocation_position;
	unsigned int vLocation_norm;
	unsigned int vbo;
	unsigned int ibo;
	unsigned int vbo_normal;
};

