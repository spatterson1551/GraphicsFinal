#pragma once
#include <vector>
#include <node.h>
#include <string>
#include <fstream>
#include <floor.h>
#include <Geometry.h>
#include <fstream>
//using namespace glm;

class SceneGraph
{
public:
	SceneGraph(void);
	SceneGraph(int, int);
	//SceneGraph(std::string file);
	~SceneGraph(void);
	void traverse(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation, int whichNode, int currentNode, float deltaX, float deltaZ);
	void addChild(SceneGraph* sg, int idx_x, int idx_z);
	//SceneGraph* operator=(SceneGraph* rSide);
	/*void setTransX(int tx) { transX = tx; }
	void setTransY(int ty) { transY = ty; } 
	void setTransZ(int tz) { transZ = tz; }*/

	float transX, transY, transZ;
	float scaleX, scaleY, scaleZ;
	float rotY;
	int width;
	int depth;
	Geometry* geom;
	SceneGraph** children;
};


