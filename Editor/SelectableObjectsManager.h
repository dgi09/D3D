#pragma once 
#include "TemplateManager.h"
#include "SingletonTemplate.h"
#include "ISelectable.h"
#include "Vector3.h"

class SelectableObjectsManager : public SingletonTemplate<SelectableObjectsManager> ,public TemplateManager < ISelectable >
{
	friend class SingletonTemplate < SelectableObjectsManager > ;

	SelectableObjectsManager();
	~SelectableObjectsManager();

public:

	void TrySelect(Vector3 rayOrigin, Vector3 rayDirection);
};