#include "FPSCameraController.h"
#include "Camera.h"

using namespace DirectX;


FPSCameraController::FPSCameraController()
{
	for (int i = 0; i < 4; i++)
	{
		keyDown[i] = false;
	}

	mouseButtonDown[0] = mouseButtonDown[1] = false;
	mouseMove = false;
}

void FPSCameraController::SetCamera(CameraPtr camera)
{
	cam = camera;
	drag = true;
}

void FPSCameraController::Update()
{
	Camera * camera = cam.Get();

	if (keyDown[FPSBind_Key_Left] || keyDown[FPSBind_Key_Right] || keyDown[FPSBind_Key_Up]
		|| keyDown[FPSBind_Key_Down])
	{

		Vector3 lookNormal  = camera->GetLookDirection().Normalize();
		

		lookNormal = lookNormal * movementSpeed;

		Vector3 rightNormal = camera->GetRightNormal() * movementSpeed;

		Vector3 camPos,camLookAt;
		camPos = camera->GetPosition();
		camLookAt = camera->GetLookAt();

		if (keyDown[FPSBind_Key_Up])
		{
			
			camPos = camPos + lookNormal;
			camLookAt = camLookAt + lookNormal;
		}
		if (keyDown[FPSBind_Key_Down])
		{
			lookNormal = lookNormal * -1;

			camPos = camPos + lookNormal;
			camLookAt = camLookAt + lookNormal;
		}

		if (keyDown[FPSBind_Key_Left])
		{
			rightNormal = rightNormal * -1;

			camPos = camPos + rightNormal;
			camLookAt = camLookAt + rightNormal;
		}
		if (keyDown[FPSBind_Key_Right])
		{
			camPos = camPos + rightNormal;
			camLookAt = camLookAt + rightNormal;
		}

		camera->SetPosition(camPos);
		camera->LookAt(camLookAt);
	}

	if(mouseButtonDown[FPSBind_Mouse_Right] && !drag)
	{
		drag = true;
		lastMouseX = mouseX;
		lastMouseY = mouseY;
	}
	
	if (!mouseButtonDown[FPSBind_Mouse_Right])
	{
		drag = false;
	}
	

	if(drag && mouseMove)
	{
		int offSetX = mouseX - lastMouseX;
		int offSetY = mouseY - lastMouseY;

		Vector3 lat = camera->GetLookDirection();
		Vector3 camPos = camera->GetPosition();
		Vector3 rightN = camera->GetRightNormal();
		Vector3 upN = camera->GetUpNormal();

		XMVECTOR lookAt = XMLoadFloat3((XMFLOAT3*)&lat);
		XMVECTOR upV = XMLoadFloat3((XMFLOAT3*)&upN);
		XMVECTOR right = XMLoadFloat3((XMFLOAT3*)&rightN);

		XMMATRIX rotateX = XMMatrixIdentity();
		XMMATRIX rotateY = XMMatrixIdentity();

		if(offSetX != 0)
			rotateX = XMMatrixRotationAxis(upV,XMConvertToRadians((float)offSetX * 0.4f));
		if(offSetY != 0)
			rotateY = XMMatrixRotationAxis(right,XMConvertToRadians((float)offSetY * 0.4f));

		XMVECTOR result = XMVector3Transform(lookAt,rotateX * rotateY);

		Vector3 res;
		XMStoreFloat3((XMFLOAT3*)&res,result);

		camera->LookAt(camPos + res);

		lastMouseX = mouseX;
		lastMouseY = mouseY;
		
	}
	
}

void FPSCameraController::SetMovementSpeed(float speed)
{
	movementSpeed = speed;
}

void FPSCameraController::InjectKeyDown(FPSControllerBind key)
{
	keyDown[key] = true;
}

void FPSCameraController::InjectKeyUp(FPSControllerBind key)
{
	keyDown[key] = false;
}

void FPSCameraController::InjectMouseDown(FPSControllerBind button)
{
	mouseButtonDown[button] = true;
}
void FPSCameraController::InjectMouseUp(FPSControllerBind button)
{
	mouseButtonDown[button] = false;
}

void FPSCameraController::InjectMouseMove(bool val)
{
	mouseMove = val;
}
void FPSCameraController::InjectMousePos(unsigned int x, unsigned int y)
{
	mouseX = x;
	mouseY = y;
}