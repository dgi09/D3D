#pragma once 

#include "Common.h"
#include "Vector3.h"

class EXPORT AABB
{
public:
	Vector3 min;
	Vector3 max;

	bool RayIntersact(Vector3 origin, Vector3 dir);
};