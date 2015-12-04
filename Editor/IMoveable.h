#pragma once 

#include "Vector3.h"

class IMoveable
{
public:
	virtual void Move(Vector3 offset) = 0;
};