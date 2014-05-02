#pragma once
#include <box.h>
#include <Geometry.h>
class Floor : public Geometry
{
public:
	Floor(void);
	Floor(float, float);
	~Floor(void);

	//static void draw(glm::mat4 m, unsigned int u_modelLocation, float floorX, float floorZ);
	void draw(glm::mat4 m, unsigned int, unsigned int);
	float width;
	float depth;
};

