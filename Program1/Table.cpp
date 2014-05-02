#include "table.h"
#include "Cube.h"


Table::Table(void)
{
	height = 1.0f;
}


Table::~Table(void)
{
}

void Table::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {

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