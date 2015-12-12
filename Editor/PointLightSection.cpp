#include "PointLightSection.h"
#include "Utils.h"

PointLightSection::PointLightSection(wxWindow * parent)
{
	s = new WX_PointLightSection(parent);
	s->propGrid->Bind(wxEVT_PG_CHANGED, &PointLightSection::OnChange, this);
}

void PointLightSection::SetPosition(Vector3 pos)
{
	s->posX->SetValue(wxVariant(pos.x));
	s->posY->SetValue(wxVariant(pos.y));
	s->posZ->SetValue(wxVariant(pos.z));
}

Vector3 PointLightSection::GetPosition()
{
	Vector3 pos;
	pos.x = (float)s->posX->GetValue().GetDouble();
	pos.y = (float)s->posY->GetValue().GetDouble();
	pos.z = (float)s->posZ->GetValue().GetDouble();

	return pos;
}

void PointLightSection::SetDiffuse(Color color)
{
	wxVariant variant;
	wxColour col = Utils::ColorToWxColour(color);
	variant << col;

	s->Diffuse->SetValue(variant);
}
Color PointLightSection::GetDiffuse()
{
	wxVariant variant = s->Diffuse->GetValue();
	wxColour col;
	col << variant;
	return Utils::WxColourToColor(col);
}

void PointLightSection::SetRange(float val)
{
	s->Range->SetValue(wxVariant(val));
}
float PointLightSection::GetRange()
{
	return (float)s->Range->GetValue().GetDouble();
}

wxWindow * PointLightSection::GetWXControl()
{
	return s;
}

void PointLightSection::SetOnChangeCallback(std::function<void(PointLightSectionChange)> callback)
{
	onChangeCallback = callback;
}

void PointLightSection::OnChange(wxPropertyGridEvent & evt)
{
	if (onChangeCallback)
	{
		wxString name = evt.GetPropertyName();
		if (name == "X" || name == "Z" || name == "Y")
		{
			onChangeCallback(PLSC_POSITION);
		}
		else if (name == "Diffuse")
		{
			onChangeCallback(PLSC_DIFFUSE);
		}
		else if (name == "Range")
		{
			onChangeCallback(PLSC_RANGE);
		}
	}
}