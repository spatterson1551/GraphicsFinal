#pragma once
#include <box.h>
#include <Geometry.h>
class Floor : public Geometry
{
public:
	Floor(void);
	Floor(float, float, unsigned int, unsigned int);
	~Floor(void);

	//static void draw(glm::mat4 m, unsigned int u_modelLocation, float floorX, float floorZ);
	void draw(glm::mat4 m, unsigned int, unsigned int);
	void draw(glm::mat4 m, unsigned int, unsigned int, vec3);
	float width;
	float depth;
	unsigned int vLocation_position;
	unsigned int vLocation_norm;
	unsigned int vbo;
	unsigned int vbo_norm;
	unsigned int vbo_color;
	unsigned int ibo;
};



