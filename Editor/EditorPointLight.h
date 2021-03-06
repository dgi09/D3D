#pragma once 
#include "IEditorSceneObject.h"
#include "ISelectable.h"
#include "IMoveable.h"
#include "Scene.h"
#include "PointLightSection.h"


class EditorPointLight : public IEditorSceneObject, public ISelectable, public IMoveable
{
	PointLightPtr ptr;
	StaticEntityPtr sphere;
	StaticEntityPtr bbox;

	PointLightSection * plSection;
public:
	EditorPointLight(PointLightPtr ptr);

	void OnAdd();
	void OnRemove();

	bool Select(Vector3 rayOrigin, Vector3 rayDirection);
	void OnSelect();
	void OnFocusOut();

	void Move(Vector3 offset);

private:

	void OnPLSectionChange(PointLightSectionChange ch);
};