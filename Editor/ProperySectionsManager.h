#pragma once 

#include "TransformSection.h"
#include "MaterialSection.h"
#include "PointLightSection.h"
#include "DirectLightSection.h"

class PropertySectionsManager
{
	static wxWindow * parent;
	
public:

	static void SetParent(wxWindow * w);
	static TransformSection * GetTransformSection();
	static MaterialSection * GetMaterialSection();
	static PointLightSection * GetPointLightSection();
	static DirectLightSection * GetDirectLightSection();
};