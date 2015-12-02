#pragma once 
#include "Common.h"
#include "Scene.h"
#include "InputManager.h"

enum EXPORT FPSControllerBind
{
	FPSBind_Key_Left = 0,
	FPSBind_Key_Right = 1,
	FPSBind_Key_Up = 2,
	FPSBind_Key_Down = 3,
	FPSBind_Mouse_Left = 0,
	FPSBind_Mouse_Right = 1
};

class EXPORT FPSCameraController
{

	CameraPtr cam;

	int lastMouseX;
	int lastMouseY;

	bool drag;

	float movementSpeed;

	bool keyDown[4];
	bool mouseButtonDown[2];
	bool mouseMove;

	unsigned int mouseX;
	unsigned int mouseY;
public:
	
	FPSCameraController();

	void SetCamera(CameraPtr camera);
	void SetMovementSpeed(float speed);

	void Update();

	void InjectKeyDown(FPSControllerBind key);
	void InjectKeyUp(FPSControllerBind key);

	void InjectMouseDown(FPSControllerBind button);
	void InjectMouseUp(FPSControllerBind button);

	void InjectMouseMove(bool val);
	void InjectMousePos(unsigned int x, unsigned int y);

};
