#pragma once 
#include "IEditorUpdateable.h"
#include "SingletonTemplate.h"
#include <vector>

class EditorUpdateableManager : public SingletonTemplate < EditorUpdateableManager >
{

	std::vector<IEditorUpdateable*> elements;

	
public:
	EditorUpdateableManager();
	~EditorUpdateableManager();

	void AddUpdateable(IEditorUpdateable * updateable);
	void RemoveUpdateable(IEditorUpdateable * updateable);

	void UpdateAll();
};

