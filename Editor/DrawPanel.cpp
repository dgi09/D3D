#include "DrawPanel.h"
#include "CustomPanel.h"
#include "EditorUpdateableManager.h"

DrawPanel::DrawPanel(wxWindow * parent,wxPoint pos,wxSize size,int flags,wchar_t name[11])
{
	wxControl = new CustomPanel(parent, wxID_ANY, pos, size, flags,name);
	wxControl->Bind(wxEVT_PAINT,&DrawPanel::OnPanelDraw,this);
	wxControl->Bind(wxEVT_IDLE,&DrawPanel::OnPanelIdle,this);
	wxControl->Bind(wxEVT_ERASE_BACKGROUND,&DrawPanel::OnBackErase,this);
	wxControl->Bind(wxEVT_DESTROY,&DrawPanel::OnDestroy,this);
	
	wxControl->Bind(wxEVT_LEFT_DOWN, &DrawPanel::LeftMouseButtonDown, this);
	wxControl->Bind(wxEVT_LEFT_UP, &DrawPanel::LeftMouseButtonUp, this);

	wxControl->Bind(wxEVT_RIGHT_DOWN, &DrawPanel::RightMouseButtonDown, this);
	wxControl->Bind(wxEVT_RIGHT_UP, &DrawPanel::RightMouseButtonUp, this);

	wxControl->Bind(wxEVT_CHAR_HOOK, &DrawPanel::KeyDown, this);
	wxControl->Bind(wxEVT_KEY_UP, &DrawPanel::KeyUp, this);
	wxControl->Bind(wxEVT_MOTION, &DrawPanel::MouseMotion, this);

	window = Window::Create(size.GetWidth(),size.GetHeight(),(HWND)wxControl->GetHandle());
	scene = window->GetScene();
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
	EditorUpdateableManager::GetPtr()->UpdateAll();

	scene->DrawAll();
}

void DrawPanel::OnMouseEvent(std::function<void(MouseEvent & evt)> meh)
{
	mouseEventHandler = meh;
}

void DrawPanel::OnKeyboardEvent(std::function<void(KeyboardEvent & evt)> keh)
{
	keyboardEventHandler = keh;
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
	return window->GetScene();
}

void DrawPanel::OnDestroy(wxEvent & evt)
{
	Window::Destroy(window);
}

// mouse events

void DrawPanel::LeftMouseButtonDown(wxMouseEvent & e)
{
	MouseEvent ev;
	ev.button = ME_MB_LEFT;
	ev.type = MET_BUTTONDOWN;
	ev.x = e.GetX();
	ev.y = e.GetY();
	
	wxControl->SetFocus();

	mouseEventHandler(ev);
}

void DrawPanel::LeftMouseButtonUp(wxMouseEvent & e)
{
	MouseEvent ev;
	ev.button = ME_MB_LEFT;
	ev.type = MET_BUTTONUP;
	ev.x = e.GetX();
	ev.y = e.GetY();

	mouseEventHandler(ev);

	ev.type = MET_CLICK;

	mouseEventHandler(ev);
}

void DrawPanel::RightMouseButtonDown(wxMouseEvent & e)
{
	MouseEvent ev;
	ev.button = ME_MB_RIGHT;
	ev.type = MET_BUTTONDOWN;
	ev.x = e.GetX();
	ev.y = e.GetY();

	wxControl->SetFocus();

	mouseEventHandler(ev);
}

void DrawPanel::RightMouseButtonUp(wxMouseEvent & e)
{
	MouseEvent ev;
	ev.button = ME_MB_RIGHT;
	ev.type = MET_BUTTONUP;
	ev.x = e.GetX();
	ev.y = e.GetY();

	mouseEventHandler(ev);

	ev.type = MET_CLICK;

	mouseEventHandler(ev);
}

void DrawPanel::MouseMotion(wxMouseEvent & e)
{
	MouseEvent ev;
	ev.type = MET_MOTION;
	ev.x = e.GetX();
	ev.y = e.GetY();

	mouseEventHandler(ev);
}

void DrawPanel::KeyDown(wxKeyEvent & e)
{
	KeyboardEvent ev;
	ev.type = KET_KEYDOWN;
	ev.keyCode = (wxKeyCode)e.GetKeyCode();
	
	keyboardEventHandler(ev);
}
void DrawPanel::KeyUp(wxKeyEvent & e)
{
	KeyboardEvent ev;
	ev.type = KET_KEYUP;
	ev.keyCode = (wxKeyCode)e.GetKeyCode();

	keyboardEventHandler(ev);
}