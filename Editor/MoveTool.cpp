#include "MoveTool.h"
#include "Scene.h"
#include "MainScene.h"
#include "ActiveMoveable.h"

MoveTool::MoveTool()
{
	drag = false;
}
void MoveTool::PreUse()
{

}
void MoveTool::OnMouseEvent(MouseEvent & evt)
{
	if (evt.type == MET_BUTTONDOWN)
	{
		if (evt.button == ME_MB_LEFT)
		{
			drag = true;
			prevX = evt.x;
			prevY = evt.y;
		}
	}

	if (evt.type == MET_BUTTONUP)
	{
		if (evt.button == ME_MB_LEFT)
		{
			drag = false;
		}
	}

	if (evt.type == MET_MOTION && drag)
	{
		int offX = evt.x - prevX;
		int offY = evt.y - prevY;

		CameraPtr ptr = MainScene::Get()->GetActiveCamera();
		Camera * cam = ptr.Get();
		cam->CalcVectors();


		if (offY != 0)
			ActiveMoveable::Move(cam->GetUpNormal() * (offY / abs(offY)) * -1);
		
		if (offX != 0)
			ActiveMoveable::Move(cam->GetRightNormal() * (offX / abs(offX)));

		prevX = evt.x;
		prevY = evt.y;
	}
}
void MoveTool::OnKeyboardEvent(KeyboardEvent & evt)
{

}
void MoveTool::PostUse()
{

}