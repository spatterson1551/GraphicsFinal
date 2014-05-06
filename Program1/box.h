#pragma once
#define GLEW_STATIC
#include "glew.h"
#include <QGLWidget>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <QDebug>
#include "Geometry.h"

using glm::vec3;

class Box : public Geometry
{
public:
	Box(unsigned int, unsigned int);
	~Box(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
	void catmullClark() { return; }
	void draw(glm::mat4 m, unsigned int, unsigned int, vec3);

	static vec3 cubeVerts[24];
	static vec3 vertColor[24];
	static unsigned int indices[36];
	unsigned int vLocation_position;
	unsigned int vLocation_norm;
	unsigned int vbo;
	unsigned int vbo_norm;
	unsigned int vbo_color;
	unsigned int ibo;
private:
};

