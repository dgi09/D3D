#include "InputManager.h"
#include <Windows.h>

InputManager::InputManager()
{

	mouseMove = false;
	mouseX = 0;
	mouseY = 0;
}

InputManager::~InputManager()
{

	
}

void InputManager::Init()
{

	for (int i = 0; i < 282; i++)
	{
		keys[i] = false;
	}
	
	for (int i = 0; i < 4; i++)
	{
		currentStateDown[i] = false;
		lastStateDown[i] = false;
	}
	
}

void InputManager::PreUpdate()
{
	for (int i = 0; i < 4; i++)
	{
		lastStateDown[i] = currentStateDown[i];
	}
}


void InputManager::Update(SDL_Event evt)
{
	
	if (evt.type == SDL_MOUSEBUTTONDOWN)
	{
		if (evt.button.button > 0 && evt.button.button < 4)
		{
			currentStateDown[evt.button.button - 1] = true;
		}

	}
	else if (evt.type == SDL_MOUSEBUTTONUP)
	{
		if (evt.button.button > 0 && evt.button.button < 4)
		{
			currentStateDown[evt.button.button - 1] = false;
		}
	}

	if (evt.type == SDL_KEYDOWN)
	{
		keys[evt.key.keysym.scancode] = true;
	}
	else if (evt.type == SDL_KEYUP)
	{
		keys[evt.key.keysym.scancode] = false;
	}
	
	mouseX = evt.button.x;
	mouseY = evt.button.y;

	if (evt.type == SDL_MOUSEMOTION)
	{
		mouseMove = true;
	}
	else
		mouseMove = false;
}

bool InputManager::KeyPressed(unsigned int key)
{
	if(key >= 0 && key <= 281)
	{
		return keys[key];
	}

	return false;
}

bool InputManager::MouseMove()
{
	return mouseMove;
}

int InputManager::GetMouseX()
{
	return mouseX;
}

int InputManager::GetMouseY()
{
	return mouseY;
}

bool InputManager::MouseButtonDown(MouseButton button)
{
	return currentStateDown[(int)button];
}

bool InputManager::MouseButtonClick(MouseButton button)
{
	return !currentStateDown[(int)button] && lastStateDown[button];
}