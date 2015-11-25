#pragma once 
#include "Common.h"

enum EXPORT MouseButton
{
	B_LEFT = 0,
	B_RIGHT
};

class EXPORT IInput
{
protected:
	int mouseX, mouseY;
	unsigned char keys[256];
	bool mouseMove;
public:
	virtual bool KeyPressed(unsigned int key) = 0;
	virtual bool MouseButtonDown(MouseButton button) = 0;
	virtual bool MouseMove() = 0;

	virtual int GetMouseX() = 0;
	virtual int GetMouseY() = 0;


};
