#include "SelectableObjectsManager.h"

SelectableObjectsManager::SelectableObjectsManager()
{

}
SelectableObjectsManager::~SelectableObjectsManager()
{
	elements.clear();
}



void SelectableObjectsManager::TrySelect(Vector3 rayOrigin, Vector3 rayDirection)
{
	for (std::vector<ISelectable*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if ((*it)->Select(rayOrigin, rayDirection))
		{
			(*it)->OnSelect();
			return;
		}
	}
}