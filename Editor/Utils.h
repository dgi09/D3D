#pragma once 
#include "Scene.h"
#include "wx/wx.h"
#include "Color.h"

class Utils
{
	static unsigned int current;
public:
	static StaticEntityPtr CreateBBoxEntity(EntityBase * entity);
	static Color WxColourToColor(wxColour val);
	static wxColour ColorToWxColour(Color val);
};