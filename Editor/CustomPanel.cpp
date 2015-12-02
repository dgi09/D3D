#include "CustomPanel.h"

CustomPanel::CustomPanel(wxWindow *parent,
	wxWindowID winid,
	const wxPoint& pos,
	const wxSize& size,
	long style,
	const wxString& name) : wxPanel(parent, winid, pos, size)
{

}

CustomPanel::~CustomPanel()
{

}

bool CustomPanel::AcceptsFocusFromKeyboard() const
{
	return false;
}
bool CustomPanel::AcceptsFocus() const
{
	return false;
}