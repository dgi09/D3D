#pragma once 
#include <wx/wx.h>


class PropertiesPanel
{
	static wxPanel * panel;
public:

	static void SetPanel(wxPanel * p);
	static void Clear();
	static void Add(wxWindow * window);
};