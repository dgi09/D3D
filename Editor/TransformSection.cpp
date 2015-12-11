#include "TransformSection.h"

TransformSection::TransformSection(wxWindow * parent)
{
	wx_transformSection = new WX_TransformSection(parent);
	propGrid = (wxPropertyGrid*)wx_transformSection->propGrid;

	propGrid->Bind(wxEVT_PG_CHANGED, &TransformSection::OnProperyChange, this);

	propPosX = wx_transformSection->posX;
	propPosY = wx_transformSection->posY;
	propPosZ = wx_transformSection->posZ;

	propRotX = wx_transformSection->roll;
	propRotY = wx_transformSection->yaw;
	propRotZ = wx_transformSection->pitch;

	propScaleX = wx_transformSection->scaleX;
	propScaleY = wx_transformSection->scaleY;
	propScaleZ = wx_transformSection->scaleZ;
}

void TransformSection::SetPosition(Vector3 pos)
{
	propPosX->SetValue(wxVariant(pos.x));
	propPosY->SetValue(wxVariant(pos.y));
	propPosZ->SetValue(wxVariant(pos.z));
}

Vector3 TransformSection::GetPosition()
{
	Vector3 pos;
	pos.x = (float)propPosX->GetValue().GetDouble();
	pos.y = (float)propPosY->GetValue().GetDouble();
	pos.z = (float)propPosZ->GetValue().GetDouble();

	return pos;
}

void TransformSection::SetRotation(Vector3 rot)
{
	propRotX->SetValue(wxVariant(rot.x));
	propRotY->SetValue(wxVariant(rot.y));
	propRotZ->SetValue(wxVariant(rot.z));
}

Vector3 TransformSection::GetRotation()
{
	Vector3 rot;
	rot.x = (float)propRotX->GetValue().GetDouble();
	rot.y = (float)propRotY->GetValue().GetDouble();
	rot.z = (float)propRotZ->GetValue().GetDouble();

	return rot;
}

void TransformSection::SetScale(Vector3 scale)
{
	propScaleX->SetValue(wxVariant(scale.x));
	propScaleY->SetValue(wxVariant(scale.y));
	propScaleZ->SetValue(wxVariant(scale.z));
}

Vector3 TransformSection::GetScale()
{
	Vector3 scale;
	scale.x = (float)propScaleX->GetValue().GetDouble();
	scale.y = (float)propScaleY->GetValue().GetDouble();
	scale.z = (float)propScaleZ->GetValue().GetDouble();

	return scale;
}

void TransformSection::SetOnChangeCallback(std::function<void(TransformSectionChange ch)> callback)
{
	onChangeCallback = callback;
}

void TransformSection::OnProperyChange(wxPropertyGridEvent & evt)
{
	if (onChangeCallback)
	{
		wxString name = evt.GetPropertyName();
		if (name == "X" || name == "Y" || name == "Z")
		{
			onChangeCallback(TSC_POSITION);
		}
		else if (name == "Roll" || name == "Yaw" || name == "Pitch")
		{
			onChangeCallback(TSC_ROTATION);
		}
		else
		{
			onChangeCallback(TSC_SCALE);
		}
	}
	

}

wxWindow * TransformSection::GetWXControl()
{
	return wx_transformSection;
}