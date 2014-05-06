#include "EasyBMP.h"
#include "raycast.h"
#include "intersectTest.h"
#include "..\glm\glm.hpp"

using namespace std;
using namespace glm;

void raycast(mat4 cameraMatrix) {
	int width = 800;
	int height = 600;

	const float Wd2 = width/2;
	const float Hd2 = height/2;

	BMP output;
	output.SetSize(width, height);
	output.SetBitDepth(24);
	
	glm::vec4 camerapos = glm::vec4(0, 0, 0, 0);

	for(int x = 0; x < width; x++) 
	{
		for(int y = 0; y < height; y++) 
		{
			float xtemp = x - Wd2;
			float ytemp = y - Hd2;

			xtemp = xtemp/Wd2;
			ytemp = ytemp/Hd2;

			glm::vec4 pixelpos = glm::vec4(xtemp,ytemp,1,0);
			glm::vec4 ray = camerapos-pixelpos;
			ray = glm::normalize(ray);

			vec4 color = intersectTest(ray);
			
			output(x,y)->Red = color.r;
			output(x,y)->Green = color.g;
			output(x,y)->Blue = color.b;
			
		}
	}

	output.WriteToFile("raytrace.bmp");
	return;
}

vec4 intersectTest(vec4 ray) {

	//spheres - unneeded, not catmull clark
	//boxes
	//mesh


	return vec4(0, 0, 0, 0);



}