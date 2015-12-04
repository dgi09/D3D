#pragma once 

#include "IMoveable.h"

class ActiveMoveable
{
	static IMoveable * ptr;
public:

	static void Set(IMoveable * moveable);
	static void Move(Vector3 offset);
};