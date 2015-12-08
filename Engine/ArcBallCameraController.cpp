#include "ArcBallCameraController.h"

ArcBallCameraController::ArcBallCameraController()
{
	ctrKeyDown = false;
	rightMouseButtonDown = false;
	mouseMove = false;
	drag = false;
}

void ArcBallCameraController::SetCamera(CameraPtr camera)
{
	camPtr = camera;
}
void ArcBallCameraController::Update()
{
	if (rightMouseButtonDown)
	{
		if (mouseMove)
		{
			prevMouseX = mouseX;
			prevMouseY = mouseY;
			drag = true;
		}
	}
	else
	{
		drag = false;
	}

	if (drag)
	{
		Camera * cam = camPtr.Get();
		cam->CalcVectors();

		if (ctrKeyDown)
		{

		}
	}
}

void ArcBallCameraController::InjectCtrKeyDown()
{
	ctrKeyDown = true;
}
void ArcBallCameraController::InjectCtrKeyUp()
{
	ctrKeyDown = false;
}

void ArcBallCameraController::InjectRightMouseButtonDown()
{
	rightMouseButtonDown = true;
}

void ArcBallCameraController::InjectRightMouseButtonUp()
{
	rightMouseButtonDown = false;
}

void ArcBallCameraController::InjectMouseMove(bool val)
{
	mouseMove = val;
}
void ArcBallCameraController::InjectMousePos(unsigned int x, unsigned int y)
{
	mouseX = x;
	mouseY = y;
}