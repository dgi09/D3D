#pragma once 
#include "IMoveable.h"
#include "ITool.h"

class MoveTool : public ITool
{
	unsigned int prevX, prevY;
	bool drag;
public:

	MoveTool();
	void PreUse();
	void OnMouseEvent(MouseEvent & evt);
	void OnKeyboardEvent(KeyboardEvent & evt);
	void PostUse();
};