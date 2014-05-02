#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <box.h>
//using std::vector;

struct Node

{
public:
	Node(void);
	~Node(void);
	std::string name;
	std::vector< std::vector<Node*> > childNodes;
	Node* next;
	glm::mat4 tMatrix;
};

