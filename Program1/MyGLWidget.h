#pragma once
#include <Windows.h>
#define GLEW_STATIC
#include "glew.h"
#include <QGLWidget>
#include <QFileDialog>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <QDebug>
#include <sceneGraph.h>
#include <Mesh.h>
#include <table.h>
#include <chair.h>
#include <floor.h>
#include <box.h>
#include <Cube.h>

using glm::vec3;

class MyGLWidget : public QGLWidget
{
	Q_OBJECT
public:
	MyGLWidget(QWidget*);
	~MyGLWidget(void);
	void generateGasket();
	void initializeGL(void);
	void paintGL(void);
	void resizeGL(int, int);
	void MyGLWidget::preOrderGraph(Node root, glm::mat4 m);
	void sgConfigFile();

	//helper function to read shader source and put it in a char array
	//thanks to Swiftless.com
	char* textFileRead(const char*);

private:

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	unsigned int vbo;
	unsigned int vbo_color;
	unsigned int vbo_norm;
	unsigned int ibo;
	unsigned int vLocation_position;
	unsigned int vLocation_color;
	unsigned int vLocation_norm;
	unsigned int u_projLocation;
	unsigned int u_modelLocation;
	unsigned int u_lightLocation;
	unsigned int u_colorLocation;
	unsigned int u_cameraPosition;
	glm::vec4 upVec;
	glm::vec4 position;
	glm::vec3 referencePt;
	glm::mat4 camera;
	glm::mat4 projection;
	glm::vec4 light;
	SceneGraph* sceneGraph;
	Mesh mesh;
	//Box lightSource;
	std::string file;
	float xAng;
	float yAng;
	float zAng;
	float z;
	float deltaX;
	float deltaZ;
	int whichNode;

public slots:
	void cameraZoom(void);
	void cameraOut(void);
	void cameraLeft(void);
	void cameraRight(void);
	void cameraUp(void);
	void cameraDown(void);
	void camUpDown(int);
	void camLeftRight(int);
	void lightUp(void);
	void lightDown(void);
	void lightIn(void);
	void lightOut(void);
	void lightLeft(void);
	void lightRight(void);
	void getConfigText(void);
	void selectFile(void);
	void nextGeometry(void);
	void objectLeft(void);
	void objectRight(void);
	void objectIn(void);
	void objectOut(void);
};