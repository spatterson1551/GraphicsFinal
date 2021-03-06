#include "box.h"
#include "Cube.h"

////////////////////////////////box vertices definition
vec3 Box::cubeVerts[24] = {
		vec3(.5,.5,.5), vec3(.5,-.5,.5), vec3(-.5,-.5,.5), vec3(-.5,.5,.5), //front
		vec3(.5,.5,-.5), vec3(.5,-.5,-.5), vec3(-.5,-.5,-.5), vec3(-.5,.5,-.5), // back
		vec3(.5,.5,.5), vec3(.5,-.5,.5), vec3(.5,-.5,-.5), vec3(.5,.5,-.5), //right
		vec3(-.5,.5,.5), vec3(-.5,-.5,.5), vec3(-.5,-.5,-.5), vec3(-.5,.5,-.5), //left
		vec3(.5,.5,.5), vec3(-.5,.5,.5), vec3(-.5,.5,-.5), vec3(.5,.5,-.5), //top
		vec3(.5,-.5,.5), vec3(-.5,-.5,.5), vec3(-.5,-.5,-.5), vec3(.5,-.5,-.5) //bottom
	};

vec3 Box::vertColor[24] = {
		vec3(0.7,0,0), vec3(0.7,0,0), vec3(0.7,0,0), vec3(0.7,0,0), //front
		vec3(1,.5,0), vec3(1,.5,0), vec3(1,.5,0), vec3(1,.5,0), // back
		vec3(.8,.8,0), vec3(.8,.8,0), vec3(.8,.8,0), vec3(.8,.8,0), //right
		vec3(0,0,.7), vec3(0,0,.7), vec3(0,0,.7), vec3(0,0,.7), //left
		vec3(0,0.7,0), vec3(0,0.7,0), vec3(0,0.7,0), vec3(0,0.7,0), //top
		vec3(1,0,0), vec3(1,0,0), vec3(1,0,0), vec3(1,0,0) //bottom
	};

///////////////////////////////box vertices definition


///////////////////////////////box indices definition
unsigned int Box::indices[36] = {
	0, 1, 3, 1, 2, 3,   // front face
	4, 5, 7, 5, 6, 7,
	8, 9, 11, 9, 10, 11,
	12, 13, 15, 13, 14, 15,
	16, 17, 19, 17, 18, 19,
	20, 21, 23, 21, 22, 23
};
//////////////////////////////////////////////////////

Box::Box(unsigned int vLocation_position, unsigned int vLocation_norm) {
	
	Box::vLocation_position = vLocation_position;
	Box::vLocation_norm = vLocation_norm;
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
	height = 1.0f;
}

Box::~Box(void)
{

}

void Box::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {
	
	//glUniformMatrix4fv(u_modelLocation, 1, GL_FALSE, &m[0][0]); //4fv means 4 floats in matrix
	//
	////glDrawArrays(GL_QUADS, 0, 24); 
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position);
	glVertexAttribPointer(vLocation_position, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glm::vec3 color = glm::vec3(1, 1, 0);
	glUniform3fv(u_colorLocation, 1, &color[0]);
	glm::mat4 transform = glm::mat4(1.0f); 
	transform = glm::translate(transform, glm::vec3(0.0f, 0.5f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
}

void Box::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation, vec3 color) {
	
	//glUniformMatrix4fv(u_modelLocation, 1, GL_FALSE, &m[0][0]); //4fv means 4 floats in matrix
	//
	////glDrawArrays(GL_QUADS, 0, 24); 
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation_position);
	glVertexAttribPointer(vLocation_position, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glUniform3fv(u_colorLocation, 1, &color[0]);
	glm::mat4 transform = glm::mat4(1.0f); 
	transform = glm::translate(transform, glm::vec3(0.0f, 0.5f, 0.0f));
	Cube::draw(m*transform, u_modelLocation, u_colorLocation);
}