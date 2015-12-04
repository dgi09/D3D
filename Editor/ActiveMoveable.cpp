#include "ActiveMoveable.h"

IMoveable * ActiveMoveable::ptr = nullptr;

void ActiveMoveable::Set(IMoveable * moveable)
{
	ptr = moveable;
}

void ActiveMoveable::Move(Vector3 offset)
{
	if (ptr)
	{
		ptr->Move(offset);
	}
}