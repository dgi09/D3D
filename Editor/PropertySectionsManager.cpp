#include "ProperySectionsManager.h"

wxWindow * PropertySectionsManager::parent = nullptr;



void PropertySectionsManager::SetParent(wxWindow * w)
{
	parent = w;
}


TransformSection * PropertySectionsManager::GetTransformSection()
{
	return new TransformSection(parent);
}

MaterialSection * PropertySectionsManager::GetMaterialSection()
{

	return new MaterialSection(parent);
}

PointLightSection * PropertySectionsManager::GetPointLightSection()
{

	return new PointLightSection(parent);
}

DirectLightSection * PropertySectionsManager::GetDirectLightSection()
{
	return new DirectLightSection(parent);
}