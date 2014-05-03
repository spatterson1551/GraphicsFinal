#include "table.h"
#include "Cube.h"


Table::Table(unsigned int vLocation_position, unsigned int vLocation_norm)
{
	height = 1.0f;

	Table::vLocation_position = vLocation_position;
	Table::vLocation_norm = vLocation_norm;
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


Table::~Table(void)
{
}

void Table::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position);
	glVertexAttribPointer(vLocation_position, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);


	glm::vec3 color = glm::vec3(1, 0, 0);
	glUniform3fv(u_colorLocation, 1, &color[0]);
	glm::mat4 transform = glm::mat4(1.0f);
	//leg 1
	transform = glm::scale(transform, glm::vec3(.1f, 1.0f, .1f));
	transform = glm::translate(transform, glm::vec3(4.5f, .5f, 4.5f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);

	//leg 2
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(.1f, 1.0f, .1f));
	transform = glm::translate(transform, glm::vec3(4.5f, .5f, -4.5f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);

	//leg 3

	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(.1f, 1.0f, .1f));
	transform = glm::translate(transform, glm::vec3(-4.5f, .5f, 4.5f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);

	// leg 4

	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(.1f, 1.0f, .1f));
	transform = glm::translate(transform, glm::vec3(-4.5f, .5f, -4.5f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);

	 //table top

	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(1.0f, .1f, 1.0f));
	transform = glm::translate(transform, glm::vec3(0.0f, 10.0f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);

}