#pragma once
#include <wx/wx.h>
#include "Window.h"
#include "Scene.h"

class DrawPanel
{
	wxPanel * wxControl;
	Window * window;
	Scene * scene;
public:
	DrawPanel(wxWindow * parent,wxPoint pos,wxSize size,int flags,wchar_t name[11]);
	~DrawPanel(void);

	wxPanel * GetWxControl();
	Scene * GetScene();
protected:
	void OnPanelDraw(wxPaintEvent & evt);
	void OnPanelIdle(wxIdleEvent & evt);
	void OnBackErase(wxEraseEvent & evt);
	void OnDestroy(wxEvent & evt);
};

