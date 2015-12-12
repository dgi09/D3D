#pragma once 
#include "WX_DirectLightSection.h"
#include "Vector3.h"
#include <functional>
#include "Color.h"
enum DirectLightSectionChange
{
	DLSC_POSITION = 0,
	DLSC_POINTTO,
	DLSC_DIFFUSE
};

typedef std::function<void(DirectLightSectionChange)> DLSCCallback;

class DirectLightSection
{
	WX_DirectLightSection * s;

	DLSCCallback onChangeCallback;
public:

	DirectLightSection(wxWindow * parent);
	
	void SetPosition(Vector3 pos);
	Vector3 GetPosition();

	void SetPointTo(Vector3 point);
	Vector3 GetPointTo();

	void SetDiffuse(Color val);
	Color GetDiffuse();

	wxWindow * GetWXControl();

	void SetOnChangeCallback(DLSCCallback callback);

private:

	void OnChange(wxPropertyGridEvent & evt);
};