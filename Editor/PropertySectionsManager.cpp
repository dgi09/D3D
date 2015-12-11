#include "ProperySectionsManager.h"

wxWindow * PropertySectionsManager::parent = nullptr;

TransformSection * PropertySectionsManager::transformSection = nullptr;
MaterialSection * PropertySectionsManager::materialSection = nullptr;

void PropertySectionsManager::SetParent(wxWindow * w)
{
	parent = w;
}
TransformSection * PropertySectionsManager::GetTransformSection()
{
	if (transformSection == nullptr)
	{
		transformSection = new TransformSection(parent);
	}

	return transformSection;
}

MaterialSection * PropertySectionsManager::GetMaterialSection()
{
	if (materialSection == nullptr)
	{
		materialSection = new MaterialSection(parent);
	}

	return materialSection;
}