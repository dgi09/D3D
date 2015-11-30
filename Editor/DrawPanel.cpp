#include "DrawPanel.h"


DrawPanel::DrawPanel(wxWindow * parent,wxPoint pos,wxSize size,int flags,wchar_t name[11])
{
	wxControl = new wxPanel(parent, wxID_ANY, pos, size, flags,name);
	wxControl->Bind(wxEVT_PAINT,&DrawPanel::OnPanelDraw,this);
	wxControl->Bind(wxEVT_IDLE,&DrawPanel::OnPanelIdle,this);
	wxControl->Bind(wxEVT_ERASE_BACKGROUND,&DrawPanel::OnBackErase,this);
	wxControl->Bind(wxEVT_DESTROY,&DrawPanel::OnDestroy,this);
	window = Window::Create(size.GetWidth(),size.GetHeight(),(HWND)wxControl->GetHandle());

}


DrawPanel::~DrawPanel(void)
{

}

wxPanel * DrawPanel::GetWxControl()
{
	return wxControl;
}

void DrawPanel::OnPanelDraw(wxPaintEvent & evt)
{
	scene->DrawAll();
}

void DrawPanel::OnPanelIdle(wxIdleEvent & evt)
{
	wxControl->Refresh(true);
}

void DrawPanel::OnBackErase(wxEraseEvent & evt)
{

}

Scene * DrawPanel::GetScene()
{
	return scene;
}

void DrawPanel::OnDestroy(wxEvent & evt)
{
	Window::Destroy(window);
}
