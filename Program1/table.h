#pragma once
#include <box.h>
#include <Geometry.h>

class Table : public Geometry
{
public:
	Table(void);
	~Table(void);

	void draw(glm::mat4 m, unsigned int, unsigned int);
};

