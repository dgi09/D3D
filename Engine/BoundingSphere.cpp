#include "BoundingSphere.h"

bool BoundingSphere::RayIntersact(Vector3 origin, Vector3 dir)
{
	float r = radius;

	float a, b, c, d;

	a = (dir.x * dir.x) + (dir.y * dir.y) + (dir.z * dir.z);
	b = ((dir.x * origin.x) + (dir.y * origin.y) + (dir.z * origin.z)) * 2.0f;
	c = ((origin.x * origin.x) + (origin.y * origin.y) + (origin.z * origin.z)) - (r * r);


	d = (b * b) - (4 * a * c);

	// if discriminant is negative the picking ray missed the sphere, otherwise it intersected the sphere.
	if (d < 0.0f)
	{
		return false;
	}

	return true;
}