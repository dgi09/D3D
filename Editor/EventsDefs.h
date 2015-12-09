#pragma once 

#include <wx\event.h>

enum ME_MouseButton
{
	ME_MB_LEFT = 1,
	ME_MB_RIGHT
};

enum ME_Type
{
	MET_BUTTONDOWN,
	MET_BUTTONUP,
	MET_CLICK,
	MET_MOTION,
	MET_WHEEL
};

struct MouseEvent
{
	ME_MouseButton button;
	ME_Type type;

	unsigned int x, y;
	int vertScroll;
};

enum KE_Type
{
	KET_KEYDOWN,
	KET_KEYUP
};

struct KeyboardEvent
{
	KE_Type type;
	wxKeyCode keyCode;
};