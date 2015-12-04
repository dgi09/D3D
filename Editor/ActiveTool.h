#pragma once 
#include "ITool.h"
#include "EventsDefs.h"

class ActiveTool
{
	static ITool * tool;
public:

	static void Set(ITool * t);
	static void OnMouseEvent(MouseEvent & evt);
	static void OnKeyboardEvent(KeyboardEvent & evt);

};