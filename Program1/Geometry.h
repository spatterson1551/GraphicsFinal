#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class Geometry
{
public:
	Geometry(void);
	~Geometry(void);

	//virtual float getHeight() { return height; }
	virtual void draw(glm::mat4 m, unsigned int, unsigned int) = 0;
	virtual void draw(glm::mat4 m, unsigned int, unsigned int, glm::vec3) = 0;

	float height;
};

