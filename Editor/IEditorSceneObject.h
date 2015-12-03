#pragma once 

class IEditorSceneObject
{
public:
	virtual void OnAdd() = 0;
	virtual void OnRemove() = 0;
};