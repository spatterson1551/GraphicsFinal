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
	Box();
	~Box(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
	static vec3 cubeVerts[24];
	static vec3 vertColor[24];
	static unsigned int indices[36];

private:
};

