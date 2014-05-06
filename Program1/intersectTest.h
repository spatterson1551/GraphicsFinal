#ifndef INTERSECTTEST_H
#define INTERSECTTEST_H

#include "../glm/glm.hpp"

using namespace glm;

//Need intersection test to return colors
//Combine colors into a bitmap
//Store bitmap locally

double RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T);
//vec4 RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T);

double RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T);
//vec4 RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T);

double RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T);
//vec4 RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T);


#endif