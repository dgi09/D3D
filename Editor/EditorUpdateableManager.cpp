#include "EditorUpdateableManager.h"

EditorUpdateableManager::EditorUpdateableManager()
{

}
EditorUpdateableManager::~EditorUpdateableManager()
{
	elements.clear();
}


void EditorUpdateableManager::AddUpdateable(IEditorUpdateable * updateable)
{
	elements.push_back(updateable);
}
void EditorUpdateableManager::RemoveUpdateable(IEditorUpdateable * updateable)
{
	for (std::vector<IEditorUpdateable*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if (updateable == *it)
		{
			elements.erase(it);
			return;
		}
	}
}

void EditorUpdateableManager::UpdateAll()
{
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		elements[i]->Update();
	}
}