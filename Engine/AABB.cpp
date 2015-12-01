#include "AABB.h"
#include <stdio.h>

static void swap(float & a, float & b)
{
	float temp = a;
	a = b;
	b = temp;
}

bool AABB::RayIntersact(Vector3 origin, Vector3 dir)
{
	float tmin = (min.x - origin.x) / dir.x;
	float tmax = (max.x - origin.x) / dir.x;

	if (tmin > tmax) swap(tmin, tmax);

	float tymin = (min.y - origin.y) / dir.y;
	float tymax = (max.y - origin.y) / dir.y;

	if (tymin > tymax) swap(tymin, tymax);

	if ((tmin > tymax) || (tymin > tmax))
		return false;

	if (tymin > tmin)
		tmin = tymin;

	if (tymax < tmax)
		tmax = tymax;

	float tzmin = (min.z - origin.z) / dir.z;
	float tzmax = (max.z - origin.z) / dir.z;

	if (tzmin > tzmax) swap(tzmin, tzmax);

	if ((tmin > tzmax) || (tzmin > tmax))
		return false;

	if (tzmin > tmin)
		tmin = tzmin;

	if (tzmax < tmax)
		tmax = tzmax;

	return true;
}