#include "MyGLWidget.h"
#include "../glm/gtc/matrix_transform.hpp"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {

	position = glm::vec4(0.0f, 0.0f, 10.0f, 1.0);
	referencePt = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 upVec3 = glm::normalize(glm::cross(glm::vec3(1.0f, 0.0f, 0.0f), glm::normalize(glm::vec3(0.0f, 0.0f, 0.0f) - vec3(0.0f, 6.0f, 6.0f))));
	//upVec.x = upVec3.x;
	//upVec.y = upVec3.y;
	//upVec.z = upVec3.z;
	upVec = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	xAng = 0;
	yAng = 0;
	zAng = 0;
	z = 0;
	light= glm::vec4(.0f, 4.0f, 0.0f, 1.0f);
	file = "CustomScene.txt";
}

MyGLWidget::~MyGLWidget() {
}


void MyGLWidget::initializeGL() {
	glewInit();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	//setting up buffer for colors:
	glGenBuffers(1, &vbo);   //buffer for positions
	glGenBuffers(1, &vbo_color);  //buffer for colors
	glGenBuffers(1, &vbo_norm);
	glGenBuffers(1, &ibo);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	const char* vertexSource = textFileRead("blinnphong.vert"); //blinnphong.vert
	const char* fragmentSource = textFileRead("blinnphong.frag");//blinnphong.frag
	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//"vs_color" and "vs_position":
	vLocation_position = glGetAttribLocation(shaderProgram, "vs_position"); //handles to the shader program variables
	vLocation_color = glGetAttribLocation(shaderProgram, "vs_color");
	vLocation_norm = glGetAttribLocation(shaderProgram, "vs_normal");

	//get the location of "u_modelMatrix"
	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_modelLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_lightLocation = glGetUniformLocation(shaderProgram, "u_lightPos");
	u_colorLocation = glGetUniformLocation(shaderProgram, "u_color");
	u_cameraPosition = glGetAttribLocation(shaderProgram, "u_camPos");


	glUseProgram(shaderProgram);

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


	
	glEnableVertexAttribArray(vLocation_color);
	glEnableVertexAttribArray(vLocation_norm);
	glVertexAttribPointer(vLocation_color, 3, GL_FLOAT, GL_FALSE, 0, 0); 
	glVertexAttribPointer(vLocation_norm, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//call the function to build the SceneGraph
	sgConfigFile();

	//mesh.create(vLocation_position, vLocation_norm, "surfrev1.dat");

}


void MyGLWidget::paintGL() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 identity = glm::mat4(1.0f);
	glm::mat4 rotx = glm::rotate(identity, xAng, glm::vec3(1, 0, 0));
	glm::mat4 roty = glm::rotate(identity, yAng, glm::vec3(0, 1, 0));
	glm::mat4 translation = glm::translate(identity, glm::vec3(0, 0, z));
	glm::vec4 eye = roty * rotx * translation * position;
	glm::vec4 up = roty * rotx * upVec;

	//modelMatrix = glm::scale(modelMatrix, glm::vec3(1.2, 1.2, 1.2)); // scale a little bit so we can see it better
	camera = glm::lookAt(glm::vec3(eye.x, eye.y, eye.z), referencePt, glm::vec3(up.x, up.y, up.z));

	
	glm::vec4 temp = camera * light;
	glUniform4fv(u_lightLocation, 1, &temp[0]);
	glUniformMatrix4fv(u_cameraPosition, 1, GL_FALSE, &camera[0][0]); //Added for Blinn-Phong shading
	
	sceneGraph->traverse(camera, u_modelLocation, u_colorLocation);

	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, vec3(light));
	trans = camera * trans;
	//lightSource.draw(trans, u_modelLocation, u_colorLocation);

	//mesh.draw(camera, u_modelLocation, u_colorLocation);

	glFlush();
}

void MyGLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

	projection = glm::perspective(90.0f, static_cast<float>(width) / static_cast<float>(height), 0.1f, 30.0f);

	glUniformMatrix4fv(u_projLocation, 1, GL_FALSE, &projection[0][0]);
}

//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}

void MyGLWidget::cameraZoom() {

	z -= .3;
	update();
}
void MyGLWidget::cameraOut() {

	z += .3;
	update();
}
void MyGLWidget::cameraLeft() {
	
	yAng -= 2;
	update();
}
void MyGLWidget::cameraRight() {

	yAng += 2;
	update();
}
void MyGLWidget::cameraUp() {
	
	xAng -= 2;
		
	update();
}
void MyGLWidget::cameraDown() {
	
	xAng += 2;

	update();
}

void MyGLWidget::camUpDown(int value) {

	xAng = (-1*value);
	update();
}

void MyGLWidget::camLeftRight(int value) {
	
	yAng = value;
	update();
}

void MyGLWidget::lightUp(void) {

	light.y += 1.0f;
	update();
}

void MyGLWidget::lightDown(void) {

	light.y -= 1.0f;
	update();
}

void MyGLWidget::lightIn(void) {

	light.z -= .5;
	update();
}
void MyGLWidget::lightOut(void) {

	light.z += .5;
	update();
}
void MyGLWidget::lightLeft(void) {

	light.x -= 1.0f;
	update();
}
void MyGLWidget::lightRight(void) {

	light.x += 1.0f;
	update();
}

void MyGLWidget::getConfigText(void) {

}

void MyGLWidget::selectFile(void) {
	
	QString path = QFileDialog::getOpenFileName(this, "Select Config File", QDir::currentPath());
	file = path.toStdString();
	delete sceneGraph;
	sgConfigFile();
	update();
}

void MyGLWidget::sgConfigFile() {

	std::ifstream fin;
	fin.open(file);

	//set up the floor which is the "root node"
	int width;
	int depth;
	int num;
	std::string name;
	std::string fileName;
	fin >> width;
	fin >> depth;
	fin >> num;
	sceneGraph = new SceneGraph(width, depth);
	sceneGraph->width = width;
	sceneGraph->depth = depth;
	sceneGraph->geom = new Floor(width, depth);
	sceneGraph->transX = 0.0f;
	sceneGraph->transY = 0.0f;
	sceneGraph->transZ = 0.0f;
	sceneGraph->scaleX = 1.0f;//width;
	sceneGraph->scaleY = 1.0f;//.1f;
	sceneGraph->scaleZ = 1.0f;//depth;
	sceneGraph->rotY = 0.0f;
	// end floor
	
	SceneGraph *sg;

	//now loop through num times and create all of the nodes
	for (int i = 0; i < num; i++) {
		sg = new SceneGraph;
		fin >> name;
		if (name == "mesh") {
			fin >> fileName;
			int temp;
			fin >> temp;
			fin >> sg->transX;
			fin >> sg->transZ;
			fin >> sg->rotY;
			fin >> sg->scaleX;
			fin >> sg->scaleY;
			fin >> sg->scaleZ;
			sg->geom = new Mesh(fileName, vLocation_position, vLocation_norm);
			sg->width = width;
			sg->depth = depth;
		} else {
			fin >> sg->transX;
			fin >> sg->transZ;
			fin >> sg->rotY;
			fin >> sg->scaleX;
			fin >> sg->scaleY;
			fin >> sg->scaleZ;
			if (name == "chair") {
				sg->geom = new Chair;
			} else if (name == "box") {
				sg->geom = new Box;
			} else if (name == "table") {
				sg->geom = new Table;
			}
		}
		sg->width = width;
		sg->depth = depth;
		sceneGraph->addChild(sg, sg->transX, sg->transZ);
		delete sg;
	}
	// end loop



}