#include "floor.h"
#include "Cube.h"


Floor::Floor(void)
{
	height = .1f;
	width = 5.0f;
	depth = 5.0f;
}

Floor::Floor(float w, float d) {

	width = w;
	depth = d;
	height = .1f;
}


Floor::~Floor(void)
{
}



void Floor::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {


	glm::vec3 color = glm::vec3(0, 1, 0);
	glUniform3fv(u_colorLocation, 1, &color[0]);
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(width, .1f, depth));
	transform = glm::translate(transform, glm::vec3(0.0f, .5f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
	// wall 1
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(.2f, 2.0f, depth+.4f));
	transform = glm::translate(transform, glm::vec3((((width/2)*5.0f)+.6f), .5f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
	// wall 2
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(.2f, 2.0f, depth+.4f));
	transform = glm::translate(transform, glm::vec3(((-(width/2)*5.0f)-.6f), .5f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
	// wall 3
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(width+.4f, 2.0f, .2f));
	transform = glm::translate(transform, glm::vec3(0.0f, .5f, ((depth/2)*5.0f)+.6f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
	// wall 4
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(width+.4f, 2.0f, .2f));
	transform = glm::translate(transform, glm::vec3(0.0f, .5f, -((depth/2)*5.0f)-.6f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
}