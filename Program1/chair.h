#pragma once
#include <box.h>
#include <Geometry.h>
class Chair : public Geometry
{
public:
	Chair(unsigned int, unsigned int);
	~Chair(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
	void catmullClark() { return; }
	unsigned int vLocation_position;
	unsigned int vLocation_norm;
	unsigned int vbo;
	unsigned int vbo_norm;
	unsigned int vbo_color;
	unsigned int ibo;
};

