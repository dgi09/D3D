#include "SelectableObjectsManager.h"

SelectableObjectsManager::SelectableObjectsManager()
{
	current = nullptr;
}
SelectableObjectsManager::~SelectableObjectsManager()
{
	elements.clear();
}



void SelectableObjectsManager::TrySelect(Vector3 rayOrigin, Vector3 rayDirection)
{
	for (std::vector<ISelectable*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if (((*it) != current) && (*it)->Select(rayOrigin, rayDirection))
		{
			RawSelect(*it);
			
		}
	}
}

void SelectableObjectsManager::RawSelect(ISelectable * selectable)
{
	if (current)
		current->OnFocusOut();

	selectable->OnSelect();

	current = selectable;
}