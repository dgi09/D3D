#pragma once 

#include "Common.h"
#include "Vector3.h"
#include "Color.h"
struct EXPORT BillboardShaderData
{
	Vector3 pos;
	float width;

	Color difuseColor;
	
	float height;
	unsigned int mode;

	float padding[2];
};