#include "PropertiesPanel.h"

wxPanel * PropertiesPanel::panel = nullptr;

void PropertiesPanel::SetPanel(wxPanel * p)
{
	panel = p;
}
void PropertiesPanel::Clear()
{
	wxWindowList list = panel->GetChildren();
	list.clear();
	panel->GetSizer()->Clear(true);
	
}
void PropertiesPanel::Add(wxWindow * window)
{
	panel->GetSizer()->Add(window);
	panel->GetSizer()->Layout();
}