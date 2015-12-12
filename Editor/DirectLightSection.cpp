#include "DirectLightSection.h"
#include "Utils.h"


DirectLightSection::DirectLightSection(wxWindow * parent)
{
	s = new WX_DirectLightSection(parent);
	s->propGrid->Bind(wxEVT_PG_CHANGED, &DirectLightSection::OnChange, this);
}

void DirectLightSection::SetPosition(Vector3 pos)
{
	s->posX->SetValue(wxVariant(pos.x));
	s->posY->SetValue(wxVariant(pos.y));
	s->posZ->SetValue(wxVariant(pos.z));
}
Vector3 DirectLightSection::GetPosition()
{
	Vector3 pos;
	pos.x = s->posX->GetValue().GetDouble();
	pos.y = s->posY->GetValue().GetDouble();
	pos.z = s->posZ->GetValue().GetDouble();

	return pos;
}

void DirectLightSection::SetPointTo(Vector3 point)
{
	s->pointToX->SetValue(wxVariant(point.x));
	s->pointToY->SetValue(wxVariant(point.y));
	s->pointToZ->SetValue(wxVariant(point.z));
}
Vector3 DirectLightSection::GetPointTo()
{
	Vector3 point;
	point.x = s->pointToX->GetValue().GetDouble();
	point.y = s->pointToY->GetValue().GetDouble();
	point.z = s->pointToZ->GetValue().GetDouble();

	return point;
}

void DirectLightSection::SetDiffuse(Color val)
{
	wxVariant color;
	wxColour col = Utils::ColorToWxColour(val);
	color << col;

	s->diffuse->SetValue(color);
}
Color DirectLightSection::GetDiffuse()
{
	wxVariant colVar = s->diffuse->GetValue();
	wxColour col;
	col << colVar;
	return Utils::WxColourToColor(col);
}

wxWindow * DirectLightSection::GetWXControl()
{
	return s;
}

void DirectLightSection::SetOnChangeCallback(DLSCCallback callback)
{
	onChangeCallback = callback;
}

void DirectLightSection::OnChange(wxPropertyGridEvent & evt)
{
	if (onChangeCallback)
	{
		wxString name = evt.GetPropertyName();
		if (name == "X" || name == "Y" || name == "Z")
		{
			onChangeCallback(DLSC_POSITION);
		}
		else if (name == "ToX" || name == "ToY" || name == "ToZ")
		{
			onChangeCallback(DLSC_POINTTO);
		}
		else
		{
			onChangeCallback(DLSC_DIFFUSE);
		}
	}
}