#pragma once 

#include "ITool.h"

class SelectTool : public ITool
{
public:
	void PreUse();
	void OnMouseEvent(MouseEvent & evt);
	void OnKeyboardEvent(KeyboardEvent & evt);
	void PostUse();
};