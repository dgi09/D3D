#pragma once 
#include "IEntity.h"
#include "ISelectable.h"
#include "IEditorSceneObject.h"
#include "Scene.h"


class EditorEntity : public IEditorSceneObject , public ISelectable
{
	IEntity * entityBase;
	StaticEntityPtr bboxEntity;

public:
	EditorEntity(IEntity * base);

	virtual void OnAdd();
	virtual void OnRemove();

	bool Select(Vector3 rayOrigin, Vector3 rayDirection);
	virtual void OnSelect();

protected:
	
	void CreateBBox();
};