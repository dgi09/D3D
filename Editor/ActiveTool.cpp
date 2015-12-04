#include "ActiveTool.h"

ITool * ActiveTool::tool = nullptr;


void ActiveTool::Set(ITool * t)
{
	if (tool)
		tool->PostUse();

	tool = t;
	tool->PreUse();
}

void ActiveTool::OnMouseEvent(MouseEvent & evt)
{
	if (tool)
		tool->OnMouseEvent(evt);
}

void ActiveTool::OnKeyboardEvent(KeyboardEvent & evt)
{
	if (tool)
		tool->OnKeyboardEvent(evt);
}