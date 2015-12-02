#pragma once 
#include <wx\wx.h>

class CustomPanel : public wxPanel
{
public:
	CustomPanel(wxWindow *parent,
		wxWindowID winid = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style =  wxNO_BORDER,
		const wxString& name = wxPanelNameStr);

	~CustomPanel();

	virtual bool AcceptsFocusFromKeyboard() const;
	virtual bool AcceptsFocus() const;
};