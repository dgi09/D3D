#pragma once 
#include "SingletonTemplate.h"
#include "IEditorSceneObject.h"
#include <vector>

class EditorSceneObjectsManager : public SingletonTemplate < EditorSceneObjectsManager >
{
	friend class SingletonTemplate < EditorSceneObjectsManager > ;
	
	std::vector<IEditorSceneObject*> elements;

	EditorSceneObjectsManager();
	~EditorSceneObjectsManager();
public:

	void AddElement(IEditorSceneObject * element);
	void RemoveElement(IEditorSceneObject * element);

};

