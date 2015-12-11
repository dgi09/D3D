#pragma once 
#include <wx/wx.h>


class PropertiesPanel
{
	static wxSizer * sizer;
public:

	static void SetSizer(wxSizer * s);
	static void Clear();
	static void Add(wxWindow * window);
};