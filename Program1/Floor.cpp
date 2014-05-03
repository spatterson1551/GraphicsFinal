#include "floor.h"
#include "Cube.h"


Floor::Floor(void)
{
	height = .1f;
	width = 5.0f;
	depth = 5.0f;
}

Floor::Floor(float w, float d, unsigned int vLocation_position, unsigned int vLocation_norm) {

	width = w;
	depth = d;
	height = .1f;

	Floor::vLocation_position = vLocation_position;
	Floor::vLocation_norm = vLocation_norm;
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &vbo_norm);
	glGenBuffers(1, &vbo_color);
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(vec3), Cube::cubeVerts, GL_STATIC_DRAW); //actually sends/connects the buffer to GPU
	glEnableVertexAttribArray(vLocation_position);
	glVertexAttribPointer(vLocation_position, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(vec3), Cube::vertColor, GL_STATIC_DRAW); //actually sends/connects the buffer to GPU

	glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
	glBufferData(GL_ARRAY_BUFFER, 24*sizeof(vec3), Cube::cubeNorms, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(unsigned int), Cube::indices, GL_STATIC_DRAW);
}


Floor::~Floor(void)
{
}



void Floor::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position);
	glVertexAttribPointer(vLocation_position, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);


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