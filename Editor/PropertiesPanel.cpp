#include "PropertiesPanel.h"

wxSizer * PropertiesPanel::sizer = nullptr;

void PropertiesPanel::SetSizer(wxSizer * s)
{
	sizer = s;
}
void PropertiesPanel::Clear()
{
	sizer->Clear();
}
void PropertiesPanel::Add(wxWindow * window)
{
	sizer->Add(window);
	sizer->RecalcSizes();
}