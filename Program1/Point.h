#pragma once
//#ifndef POINT_H
//#define POINT_H

struct Point{
	float x, y, z;
	Point::Point() {
		x = 0;
		y = 0;
		z = 0;
	}
	Point::Point(float x, float y, float z) {
		Point::x = x;
		Point::y = y;
		Point::z = z;
	}
	bool friend operator==(Point left, Point right) {
		if (left.x == right.x && left.y == right.y && left.z == right.z) {
			return true;
		} 
		return false;
	}
	//bool operator==(Point& p) {
	//	if (x == p.x && y == p.y && z == p.z) {
	//		return true;
	//	} else {
	//		return false;
	//	}
	//}

};


//#endif


