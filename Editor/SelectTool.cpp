#include "SelectTool.h"
#include "Scene.h"
#include "MainScene.h"
#include "SelectableObjectsManager.h"

void SelectTool::PreUse()
{

}
void SelectTool::OnMouseEvent(MouseEvent & evt)
{
	if (evt.type == MET_CLICK)
	{
		Camera * cam = MainScene::Get()->GetActiveCamera().Get();
		cam->CalcPickingRay((float)evt.x, (float)evt.y);

		Vector3 org = cam->GetPosition();
		Vector3 dir = cam->GetPickingRayDirection();

		SelectableObjectsManager::GetPtr()->TrySelect(org, dir);
	}
}
void SelectTool::OnKeyboardEvent(KeyboardEvent & evt)
{

}
void SelectTool::PostUse()
{

}