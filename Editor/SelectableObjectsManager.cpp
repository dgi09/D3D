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
	bool anySelected = false;
	for (std::vector<ISelectable*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if (((*it) != current) &&(*it)->Select(rayOrigin, rayDirection))
		{
			anySelected = true;
			RawSelect(*it);
			break;
		}
	}

	if (!anySelected)
	{
		if (current)
		{
			current->OnFocusOut();
			current = nullptr;
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