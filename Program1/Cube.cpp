#include "Cube.h"


Cube::Cube(void)
{
}


Cube::~Cube(void)
{
}





////////////////////////////////box vertices definition
vec3 Cube::cubeVerts[24] = {
		vec3(.5,.5,.5), vec3(.5,-.5,.5), vec3(-.5,-.5,.5), vec3(-.5,.5,.5), //front
		vec3(.5,.5,-.5), vec3(.5,-.5,-.5), vec3(-.5,-.5,-.5), vec3(-.5,.5,-.5), // back
		vec3(.5,.5,.5), vec3(.5,-.5,.5), vec3(.5,-.5,-.5), vec3(.5,.5,-.5), //right
		vec3(-.5,.5,.5), vec3(-.5,-.5,.5), vec3(-.5,-.5,-.5), vec3(-.5,.5,-.5), //left
		vec3(.5,.5,.5), vec3(-.5,.5,.5), vec3(-.5,.5,-.5), vec3(.5,.5,-.5), //top
		vec3(.5,-.5,.5), vec3(-.5,-.5,.5), vec3(-.5,-.5,-.5), vec3(.5,-.5,-.5) //bottom
	};

vec3 Cube::vertColor[24] = {
		vec3(0.7,0,0), vec3(0.7,0,0), vec3(0.7,0,0), vec3(0.7,0,0), //front
		vec3(1,.5,0), vec3(1,.5,0), vec3(1,.5,0), vec3(1,.5,0), // back
		vec3(.8,.8,0), vec3(.8,.8,0), vec3(.8,.8,0), vec3(.8,.8,0), //right
		vec3(0,0,.7), vec3(0,0,.7), vec3(0,0,.7), vec3(0,0,.7), //left
		vec3(0,0.7,0), vec3(0,0.7,0), vec3(0,0.7,0), vec3(0,0.7,0), //top
		vec3(1,0,0), vec3(1,0,0), vec3(1,0,0), vec3(1,0,0) //bottom
	};

///////////////////////////////box vertices definition

vec3 Cube::cubeNorms[24] = {
		vec3(0, 0, 1), vec3(0, 0, 1), vec3(0, 0, 1), vec3(0, 0, 1), //front
		vec3(0, 0, -1), vec3(0, 0, -1), vec3(0, 0, -1), vec3(0, 0, -1), // back
		vec3(1, 0, 0), vec3(1, 0, 0), vec3(1, 0, 0), vec3(1, 0, 0), //right
		vec3(-1, 0, 0), vec3(-1, 0, 0), vec3(-1, 0, 0), vec3(-1, 0, 0), //left
		vec3(0, 1, 0), vec3(0, 1, 0), vec3(0, 1, 0), vec3(0, 1, 0), //top
		vec3(0, -1, 0), vec3(0, -1, 0), vec3(0, -1, 0), vec3(0, -1, 0) //bottom
	};


///////////////////////////////box indices definition
unsigned int Cube::indices[36] = {
	0, 1, 3, 1, 2, 3,   // front face
	4, 5, 7, 5, 6, 7,
	8, 9, 11, 9, 10, 11,
	12, 13, 15, 13, 14, 15,
	16, 17, 19, 17, 18, 19,
	20, 21, 23, 21, 22, 23
};
//////////////////////////////////////////////////////



void Cube::draw(glm::mat4 m, unsigned int u_modelLocation, unsigned int u_colorLocation) {
	
	glUniformMatrix4fv(u_modelLocation, 1, GL_FALSE, &m[0][0]); //4fv means 4 floats in matrix
	
	//glDrawArrays(GL_QUADS, 0, 24); 
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
