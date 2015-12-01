#pragma once 
#include "Common.h"
#include <SDL.h>


enum EXPORT MouseButton
{
	B_LEFT = 0,
	B_RIGHT = 2
};

class EXPORT InputManager
{

	SDL_Event lastEvent;
	SDL_Event currentEvent;

	int mouseX, mouseY;
	bool mouseMove;
	bool keys[282];

	unsigned int widht, height;

	bool firstInit;

	bool lastStateDown[3];
	bool currentStateDown[3];
public:
	InputManager();
	~InputManager();

	void Init();
	void Update(SDL_Event evt);
	void PreUpdate();

	bool KeyPressed(unsigned int key);
	bool MouseButtonDown(MouseButton button);
	bool MouseButtonClick(MouseButton button);
	bool MouseMove();

	int GetMouseX();
	int GetMouseY();
};