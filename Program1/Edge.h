#include "Vertex.h"
#pragma once
#ifndef EDGE_H
#define EDGE_H


struct HEFace;
struct Edge {
	HEFace* face;
	Edge* pair;
	Edge* next;
	Vertex* vert;
	Point extFrom;

	Edge::Edge() {
		face = NULL;
		pair = NULL;
		next = NULL;
		vert = NULL;
		extFrom = Point(0, 0, 0);
	}


	Edge::Edge(HEFace* f, Edge* p, Edge* n, Vertex* v, Point ext) {
		face = f;
		pair = p;
		next = n;
		vert = v;
		extFrom = ext;
	}
};

#endif