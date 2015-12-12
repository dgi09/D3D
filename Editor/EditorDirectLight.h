#pragma once 
#include "IEditorSceneObject.h"
#include "ISelectable.h"
#include "IMoveable.h"
#include "Scene.h"
#include "DirectLightSection.h"


class EditorDirectLight : public IEditorSceneObject, public ISelectable, public IMoveable
{
	DirectionalLightPtr ptr;
	StaticEntityPtr sphere;
	StaticEntityPtr bbox;

	DirectLightSection * dlSection;

	Vector3 pos, pointTo;

public:
	EditorDirectLight(Vector3 pos, Vector3 pointTo);

	void OnAdd();
	void OnRemove();

	bool Select(Vector3 rayOrigin, Vector3 rayDirection);
	void OnSelect();
	void OnFocusOut();

	void Move(Vector3 offset);

private:

	void OnDLSectionChange(DirectLightSectionChange ch);
};