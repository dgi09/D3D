#pragma once 

#include "WX_TransformSection.h"
#include <wx/wx.h>
#include "Vector3.h"
#include <functional>


enum TransformSectionChange
{
	TSC_POSITION = 0,
	TSC_ROTATION,
	TSC_SCALE
};

class TransformSection
{
	WX_TransformSection * wx_transformSection;
	wxPropertyGrid * propGrid;

	wxPGProperty * propPosX;
	wxPGProperty * propPosY;
	wxPGProperty * propPosZ;

	wxPGProperty * propRotX;
	wxPGProperty * propRotY;
	wxPGProperty * propRotZ;

	wxPGProperty * propScaleX;
	wxPGProperty * propScaleY;
	wxPGProperty * propScaleZ;
	std::function<void(TransformSectionChange ch)> onChangeCallback;

public:
	TransformSection(wxWindow * parent);
	void SetPosition(Vector3 pos);
	Vector3 GetPosition();

	void SetRotation(Vector3 rot);
	Vector3 GetRotation();

	void SetScale(Vector3 scale);
	Vector3 GetScale();

	void SetOnChangeCallback(std::function<void(TransformSectionChange ch)> callback);

	wxWindow * GetWXControl();

private:

	void OnProperyChange(wxPropertyGridEvent & evt);
};