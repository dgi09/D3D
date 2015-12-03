#include "EditorSceneObjectsManager.h"

EditorSceneObjectsManager::EditorSceneObjectsManager()
{

}
EditorSceneObjectsManager::~EditorSceneObjectsManager()
{
	elements.clear();
}

void EditorSceneObjectsManager::AddElement(IEditorSceneObject * element)
{
	element->OnAdd();
	elements.push_back(element);
}
void EditorSceneObjectsManager::RemoveElement(IEditorSceneObject * element)
{
	for (std::vector<IEditorSceneObject*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if (*it == element)
		{
			element->OnRemove();
			elements.erase(it);
			return;
		}
	}
}