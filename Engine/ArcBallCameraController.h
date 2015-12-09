#pragma once 

#include "Common.h"
#include "Scene.h"


class EXPORT ArcBallCameraController
{
	bool rightMouseButtonDown;
	bool mouseMove;
	bool ctrKeyDown;

	bool drag;
	bool scroll;
	int verticalScroll;

	unsigned int prevMouseX, prevMouseY;
	unsigned int mouseX, mouseY;

	CameraPtr camPtr;

	float zoomAmount;
	float moveAmount;
	float rotateAmount;
public:
	ArcBallCameraController();

	void SetCamera(CameraPtr camera);
	void SetZoomAmount(float amount);
	void SetMoveAmount(float amount);
	void SetRotateAmount(float amount);
	void Update();

	void InjectCtrKeyDown();
	void InjectCtrKeyUp();

	void InjectRightMouseButtonDown();
	void InjectRightMouseButtonUp();

	void InjectMouseMove(bool val);
	void InjectMousePos(unsigned int x, unsigned int y);

	void InjectScroll(bool val);
	void InjectVerticalScroll(int vs);
};