#pragma once 
#include "IEditorUpdateable.h"
#include "TemplateManager.h"
#include "SingletonTemplate.h"
#include <vector>

class EditorUpdateableManager : public SingletonTemplate<EditorUpdateableManager>,public TemplateManager < IEditorUpdateable >
{
	friend class SingletonTemplate < EditorUpdateableManager > ;


	EditorUpdateableManager();
	~EditorUpdateableManager();
public:
	void UpdateAll();
};

