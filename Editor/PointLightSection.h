#pragma once 
#include "WX_PointLightSection.h"
#include "Vector3.h"
#include "Color.h"
#include <functional>


enum PointLightSectionChange
{
	PLSC_POSITION = 0,
	PLSC_DIFFUSE,
	PLSC_RANGE
};

class PointLightSection
{
	WX_PointLightSection * s;

	std::function<void(PointLightSectionChange)> onChangeCallback;

public:

	PointLightSection(wxWindow * parent);

	void SetPosition(Vector3 pos);
	Vector3 GetPosition();

	void SetDiffuse(Color color);
	Color GetDiffuse();

	void SetRange(float val);
	float GetRange();

	void SetOnChangeCallback(std::function<void(PointLightSectionChange)> callback);

	wxWindow * GetWXControl();

private:

	void OnChange(wxPropertyGridEvent & evt);
};