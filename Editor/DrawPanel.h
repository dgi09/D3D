#pragma once
#include <wx/wx.h>
#include "Window.h"
#include "Scene.h"
#include "EventsDefs.h"
#include <functional>

class DrawPanel
{
	wxPanel * wxControl;
	Window * window;
	Scene * scene;

	bool mouseMoveAfterClick;
	bool mouseButtonDown;

	std::function<void(MouseEvent & evt)> mouseEventHandler;
	std::function<void(KeyboardEvent & evt)> keyboardEventHandler;

public:
	DrawPanel(wxWindow * parent,wxPoint pos,wxSize size,int flags,wchar_t name[11]);
	~DrawPanel(void);

	wxPanel * GetWxControl();
	Scene * GetScene();

	void OnMouseEvent(std::function<void(MouseEvent & evt)> meh);
	void OnKeyboardEvent(std::function<void(KeyboardEvent & evt)> keh);

protected:
	void OnPanelDraw(wxPaintEvent & evt);
	void OnPanelIdle(wxIdleEvent & evt);
	void OnBackErase(wxEraseEvent & evt);
	void OnDestroy(wxEvent & evt);

	// mouse events

	void LeftMouseButtonDown(wxMouseEvent & e);
	void LeftMouseButtonUp(wxMouseEvent & e);
	
	void RightMouseButtonDown(wxMouseEvent & e);
	void RightMouseButtonUp(wxMouseEvent & e);
	
	void MouseMotion(wxMouseEvent & e);

	void MouseWheel(wxMouseEvent & e);

	// keyboard events
	void KeyDown(wxKeyEvent & e);
	void KeyUp(wxKeyEvent & e);

};

