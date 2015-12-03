#include "EditorUpdateableManager.h"

EditorUpdateableManager::EditorUpdateableManager()
{

}
EditorUpdateableManager::~EditorUpdateableManager()
{
	elements.clear();
}


void EditorUpdateableManager::UpdateAll()
{
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		elements[i]->Update();
	}
}