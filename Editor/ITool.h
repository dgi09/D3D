#pragma once 
#include "EventsDefs.h"

class ITool
{
public:
	virtual void PreUse() = 0;
	virtual void OnMouseEvent(MouseEvent & evt) = 0;
	virtual void OnKeyboardEvent(KeyboardEvent & evt) = 0;
	virtual void PostUse() = 0;
};