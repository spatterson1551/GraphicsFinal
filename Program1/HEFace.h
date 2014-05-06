#include "Edge.h"
#pragma once
#ifndef HEFACE_H
#define HEFACE_H


struct HEFace {
	Edge* edge;
	glm::vec3 normal;

	HEFace::HEFace() {
		edge = NULL;
		normal = glm::vec3(0, 0, 0);
	}	
	HEFace::HEFace(Edge* e, glm::vec3 n) {
		edge = e;
		normal = n;
	}
	HEFace::~HEFace() {
		edge = NULL;

	}
	/*Face::Face(Face f) {
		vert1 = f.vert1;
		vert2 = f.vert2;
		vert3 = f.vert3;
		edge = new Edge(f.
	}*/
};

#endif //face