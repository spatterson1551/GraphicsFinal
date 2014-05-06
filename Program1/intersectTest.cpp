#include "intersectTest.h"
#include <iostream>
using namespace std;

using namespace glm;

double RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	
	float radius = 1;
	float A = V0.x*V0.x + V0.y*V0.y + V0.z*V0.z;
	float B = 2*(V0.x*(P0.x - T[3][0]) + V0.y*(P0.y - T[3][1]) + V0.z*(P0.z - T[3][2]));
	float C = (P0.x - T[3][0])*(P0.x - T[3][0]) + (P0.y - T[3][1])*(P0.y - T[3][1]) + (P0.z - T[3][2])*(P0.z - T[3][2]) - pow(radius,2);

	float disc = B*B - 4*A*C;

	if(2*A == 0)
		return -1;

	if(disc == 0) {

	}
	
	if(B*B - 4*A*C == 0) {
		float t = -B/(2*A);
		return t;
	} else if(B*B - 4*A*C > 0) {
		float t1 = (-B + sqrt(B*B -4*A*C))/(2*A);
		float t2 = (-B - sqrt(B*B -4*A*C))/(2*A);

		if(t1 > t2 && t2 > 0)
			return t2;
		if(t1 < t2 && t1 > 0)
			return t1;
	}

	return -1;
}

double RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T) {
	//Test plane
	vec3 norm = normalize(cross((p2 - p1), (p3 - p1)));

	vec4 tempP0 = vec4(P0,1.0f);
	tempP0 = inverse(T)*tempP0;
	vec3 nP0 = vec3(tempP0.x, tempP0.y, tempP0.z);

	vec4 tempV0 = vec4(V0,0.0f);
	mat4 TC = T;
	TC[3][0] = 0;
	TC[3][1] = 0;
	TC[3][2] = 0;
	tempV0 = inverse(TC)*tempV0;
	vec3 nV0 = vec3(tempV0.x, tempV0.y, tempV0.z);
	
	float t = dot(norm, p1 - nP0)/dot(norm, nV0);

	if(dot(norm, nV0) == 0)
		return -1;

	if(t < 0)
		return -1;

	vec3 p = nP0 + t*nV0;

	//Test triangle
	double m1, m2, m3;
	m1 = (p1.y*p2.z*1) + (p1.z*1*p3.y) + (1*p2.y*p3.z) - (p3.y*p2.z*1) - (p3.z*1*p1.y) - (1*p2.y*p1.z);
	m2 = (p1.z*p2.x*1) + (p1.x*1*p3.z) + (1*p2.z*p3.x) - (p3.z*p2.x*1) - (p3.x*1*p1.z) - (1*p2.z*p1.x);
	m3 = (p1.x*p2.y*1) + (p1.y*1*p3.x) + (1*p2.x*p3.y) - (p3.x*p2.y*1) - (p3.y*1*p1.x) - (1*p2.x*p1.y);
	double s = sqrt(m1*m1 + m2*m2 + m3*m3);

	m1 = (p.y*p2.z*1) + (p.z*1*p3.y) + (1*p2.y*p3.z) - (p3.y*p2.z*1) - (p3.z*1*p.y) - (1*p2.y*p.z);
	m2 = (p.z*p2.x*1) + (p.x*1*p3.z) + (1*p2.z*p3.x) - (p3.z*p2.x*1) - (p3.x*1*p.z) - (1*p2.z*p.x);
	m3 = (p.x*p2.y*1) + (p.y*1*p3.x) + (1*p2.x*p3.y) - (p3.x*p2.y*1) - (p3.y*1*p.x) - (1*p2.x*p.y);
	double s1 = (sqrt(m1*m1 + m2*m2 + m3*m3))/s;

	m1 = (p.y*p3.z*1) + (p.z*1*p1.y) + (1*p3.y*p1.z) - (p1.y*p3.z*1) - (p1.z*1*p.y) - (1*p3.y*p.z);
	m2 = (p.z*p3.x*1) + (p.x*1*p1.z) + (1*p3.z*p1.x) - (p1.z*p3.x*1) - (p1.x*1*p.z) - (1*p3.z*p.x);
	m3 = (p.x*p3.y*1) + (p.y*1*p1.x) + (1*p3.x*p1.y) - (p1.x*p3.y*1) - (p1.y*1*p.x) - (1*p3.x*p.y);
	double s2 = (sqrt(m1*m1 + m2*m2 + m3*m3))/s;

	m1 = (p.y*p1.z*1) + (p.z*1*p2.y) + (1*p1.y*p2.z) - (p2.y*p1.z*1) - (p2.z*1*p.y) - (1*p1.y*p.z);
	m2 = (p.z*p1.x*1) + (p.x*1*p2.z) + (1*p1.z*p2.x) - (p2.z*p1.x*1) - (p2.x*1*p.z) - (1*p1.z*p.x);
	m3 = (p.x*p1.y*1) + (p.y*1*p2.x) + (1*p1.x*p2.y) - (p2.x*p1.y*1) - (p2.y*1*p.x) - (1*p1.x*p.y);
	double s3 = (sqrt(m1*m1 + m2*m2 + m3*m3))/s;
	
	if((s1 + s2 + s3) == 1) {
		return t;
	}
	
	return -1;
}

double RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	//Transform to local space
	vec4 tempP0 = vec4(P0,1.0f);
	tempP0 = inverse(T)*tempP0;
	vec3 nP0 = vec3(tempP0.x, tempP0.y, tempP0.z);

	vec4 tempV0 = vec4(V0,0.0f);
	mat4 TC = T;
	TC[3][0] = 0;
	TC[3][1] = 0;
	TC[3][2] = 0;
	tempV0 = inverse(TC)*tempV0;
	vec3 nV0 = vec3(tempV0.x, tempV0.y, tempV0.z);

	//Find bound points - nearest and farthest points
	vec3 nBound, fBound;
	nBound = vec3(-.5, -.5, -.5);
	fBound = vec3(.5, .5, .5);


	float tfar, tnear;
	tfar = 100000.0f;
	tnear = -100000.0f;

	if(nV0.x == 0 && (nP0.x < nBound.x || nP0.x > fBound.x))
		return -1;
	if(nV0.y == 0 && (nP0.y < nBound.y || nP0.y > fBound.y))
		return -1;
	if(nV0.z == 0 && (nP0.z < nBound.z || nP0.z > fBound.z))
		return -1;

	float t1, t2, temp;
	t1 = (nBound.x - nP0.x)/nV0.x;
	t2 = (fBound.x - nP0.x)/nV0.x;
	if(t1 > t2) {
		temp = t1;
		t1 = t2;
		t2 = temp;
	}
	if(t1 > tnear)
		tnear = t1;
	if(t2 < tfar)
		tfar = t2;
	if(tnear > tfar || tfar < 0)
		return -1;

	t1 = (nBound.y - nP0.y)/nV0.y;
	t2 = (fBound.y - nP0.y)/nV0.y;
	if(t1 > t2) {
		temp = t1;
		t1 = t2;
		t2 = temp;
	}
	if(t1 > tnear)
		tnear = t1;
	if(t2 < tfar)
		tfar = t2;
	if(tnear > tfar || tfar < 0)
		return -1;

	t1 = (nBound.z - nP0.z)/nV0.z;
	t2 = (fBound.z - nP0.z)/nV0.z;
	if(t1 > t2) {
		temp = t1;
		t1 = t2;
		t2 = temp;
	}
	if(t1 > tnear)
		tnear = t1;
	if(t2 < tfar)
		tfar = t2;
	if(tnear > tfar || tfar < 0)
		return -1;


	return tnear;
}