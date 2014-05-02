#pragma once
#include <box.h>
#include <Geometry.h>
class Chair : public Geometry
{
public:
	Chair(void);
	~Chair(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
};

