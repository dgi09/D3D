#include "ArcBallCameraController.h"
#include <cmath>


ArcBallCameraController::ArcBallCameraController()
{
	ctrKeyDown = false;
	rightMouseButtonDown = false;
	mouseMove = false;
	drag = false;
	scroll = false;
}

void ArcBallCameraController::SetCamera(CameraPtr camera)
{
	camPtr = camera;
}
void ArcBallCameraController::Update()
{
	if (drag)
	{
		Camera * cam = camPtr.Get();
		cam->CalcVectors();


		int offSetX, offSetY;
		int deltaX = mouseX - prevMouseX;
		int deltaY = mouseY - prevMouseY;

		offSetX = deltaX != 0 ? copysign(1, deltaX) : 0;
		offSetY = deltaY != 0 ? copysign(1, deltaY) : 0;

		Vector3 camPos = cam->GetPosition();
		Vector3 camLookAt = cam->GetLookAt();

		Vector3 right = cam->GetRightNormal();

		if (ctrKeyDown)
		{
			

			Vector3 up = cam->GetUpNormal();
			
			
			Vector3 move =  up * (-offSetY) * moveAmount + right * offSetX * moveAmount;

			cam->SetPosition(camPos + move);
			cam->LookAt(camLookAt + move);
		}
		else
		{
			using namespace DirectX;

			XMMATRIX rRotate = XMMatrixRotationAxis(XMLoadFloat3((XMFLOAT3*)&right), XMConvertToRadians(offSetY * rotateAmount));

			Vector3 posTarget = camPos - camLookAt;
			Vector3 pos;
			XMStoreFloat3((XMFLOAT3*)&pos, XMVector3TransformCoord(XMLoadFloat3((XMFLOAT3*)&posTarget), rRotate));

			pos = pos + camLookAt;

			XMMATRIX upRotate = XMMatrixRotationAxis(XMVectorSet(0.0f,1.0f,0.0f,0.0f), XMConvertToRadians(offSetX * rotateAmount));

			posTarget = pos - camLookAt;
			
			XMStoreFloat3((XMFLOAT3*)&pos, XMVector3TransformCoord(XMLoadFloat3((XMFLOAT3*)&posTarget), upRotate));

			pos = pos + camLookAt;

			cam->SetPosition(pos);
		}

		prevMouseX = mouseX;
		prevMouseY = mouseY;
	}

	if (scroll)
	{
		Camera * cam = camPtr.Get();

		Vector3 front = cam->GetLookAt() - cam->GetPosition();

		if (front.Lenght() > zoomAmount)
		{
			front = front.Normalize();
			front = front * (verticalScroll * zoomAmount);
			cam->Move(front.z,front.y,front.z);
		}

		scroll = false;
	}


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

void ArcBallCameraController::InjectScroll(bool val)
{
	scroll = val;
}
void ArcBallCameraController::InjectVerticalScroll(int vs)
{
	verticalScroll = vs;
}

void ArcBallCameraController::SetZoomAmount(float amount)
{
	zoomAmount = amount;
}


void ArcBallCameraController::SetMoveAmount(float amount)
{
	moveAmount = amount;
}
void ArcBallCameraController::SetRotateAmount(float amount)
{
	rotateAmount = amount;
}