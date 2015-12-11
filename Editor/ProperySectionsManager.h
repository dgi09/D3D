#pragma once 

#include "TransformSection.h"
#include "MaterialSection.h"

class PropertySectionsManager
{
	static wxWindow * parent;
	static TransformSection * transformSection;
	static MaterialSection * materialSection;

public:

	static void SetParent(wxWindow * w);
	static TransformSection * GetTransformSection();
	static MaterialSection * GetMaterialSection();
};