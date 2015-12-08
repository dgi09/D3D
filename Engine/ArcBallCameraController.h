#pragma once 

#include "Common.h"
#include "Scene.h"


class EXPORT ArcBallCameraController
{
	bool rightMouseButtonDown;
	bool mouseMove;
	bool ctrKeyDown;

	bool drag;
	unsigned int prevMouseX, prevMouseY;
	unsigned int mouseX, mouseY;

	CameraPtr camPtr;
public:
	ArcBallCameraController();

	void SetCamera(CameraPtr camera);
	void Update();

	void InjectCtrKeyDown();
	void InjectCtrKeyUp();

	void InjectRightMouseButtonDown();
	void InjectRightMouseButtonUp();

	void InjectMouseMove(bool val);
	void InjectMousePos(unsigned int x, unsigned int y);
};