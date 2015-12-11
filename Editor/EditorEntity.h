#pragma once 
#include "IEntity.h"
#include "ISelectable.h"
#include "IEditorSceneObject.h"
#include "Scene.h"
#include "IMoveable.h"
#include "TransformSection.h"
#include "MaterialSection.h"
class EditorEntity : public IEditorSceneObject , public ISelectable , public IMoveable
{
	IEntity * entityBase;
	StaticEntityPtr bboxEntity;

	TransformSection * transformSection;
	MaterialSection * materialSection;
public:
	EditorEntity(IEntity * base);

	virtual void OnAdd();
	virtual void OnRemove();

	bool Select(Vector3 rayOrigin, Vector3 rayDirection);
	virtual void OnSelect();
	virtual void OnFocusOut();

	virtual void Move(Vector3 offset);

protected:
	
	void CreateBBox();
	void UpdateBBoxTransform();
	void OnTransformSectionChange(TransformSectionChange ch);
	void OnMaterialSectionChange(MaterialSectionChange ch);

	void FillCurrentSubset();
	Material * GetCurrentMat();
};