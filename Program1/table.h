#pragma once
#include <box.h>
#include <Geometry.h>

class Table : public Geometry
{
public:
	Table(unsigned int, unsigned int);
	~Table(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
	void draw(glm::mat4 m, unsigned int, unsigned int, vec3);

	unsigned int vLocation_position;
	unsigned int vLocation_norm;
	unsigned int vbo;
	unsigned int vbo_norm;
	unsigned int vbo_color;
	unsigned int ibo;
};

