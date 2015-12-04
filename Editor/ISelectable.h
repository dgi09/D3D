#pragma once 

#include "Vector3.h"

class ISelectable
{
public:
	virtual bool Select(Vector3 rayOrigin, Vector3 rayDirection) = 0;
	virtual void OnSelect() = 0;
	virtual void OnFocusOut() = 0;
};