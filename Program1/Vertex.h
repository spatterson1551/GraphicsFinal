#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include "../glm/glm.hpp"

//struct Point {
//	float x, y, z;
//	Point::Point() {
//		x = 0;
//		y = 0;
//		z = 0;
//	}
//	Point::Point(float x, float y, float z) {
//		Point::x = x;
//		Point::y = y;
//		Point::z = z;
//	}
//};

struct Edge;
struct Vertex {
	Edge* edge;
	Point pt;

	Vertex(Point p, Edge* e) {
		edge = e;
		pt = p;
	}
};

#endif