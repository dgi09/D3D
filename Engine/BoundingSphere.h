#pragma once 
#include "Vector3.h"

class EXPORT BoundingSphere 
{
public:
	Vector3 position;
	float radius;

	bool RayIntersact(Vector3 origin, Vector3 dir);
};