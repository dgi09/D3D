#include "MaterialSection.h"
#include <string>
#include "Utils.h"

MaterialSection::MaterialSection(wxWindow * parent)
{
	wx_materialSection = new WX_MaterialSection(parent);

	wx_materialSection->cbSubsets->Bind(wxEVT_CHOICE, &MaterialSection::OnChoiceChange, this);
	wx_materialSection->propGridIllumination->Bind(wxEVT_PG_CHANGED, &MaterialSection::OnIlluminationChange, this);
	wx_materialSection->propGrid->Bind(wxEVT_PG_CHANGED, &MaterialSection::OnMaterialChange, this);
}

void MaterialSection::SetNumberOfSubsets(unsigned int i)
{
	wxChoice * choice = wx_materialSection->cbSubsets;
	choice->Clear();

	for (unsigned int y = 0; y < i; y++)
	{
		choice->AppendString(wxString(std::string("subset ") + std::to_string(y)));
	}

	choice->Select(0);
}
unsigned int MaterialSection::GetCurrentSubset()
{
	return (unsigned int )wx_materialSection->cbSubsets->GetCurrentSelection();
}

void MaterialSection::SetUseDiffuse(bool val)
{
	wx_materialSection->useDiffuse->SetValue(wxVariant(val));
}

bool MaterialSection::GetUseDiffuse()
{
	return wx_materialSection->useDiffuse->GetValue().GetBool();
}


void MaterialSection::UseBumpMap(bool val)
{
	wx_materialSection->useBump->SetValue(wxVariant(val));
}
bool MaterialSection::GetUseBumpMap()
{
	return wx_materialSection->useBump->GetValue().GetBool();
}


std::string MaterialSection::GetBumpTexture()
{
	return wx_materialSection->bumpMap->GetValue().GetString().c_str().AsChar();
}


void MaterialSection::SetIlluminate(bool val)
{
	wx_materialSection->illuminate->SetValue(wxVariant(val));
}
bool MaterialSection::GetIlluminate()
{
	return wx_materialSection->illuminate->GetValue().GetBool();
}

std::string MaterialSection::GetDiffuseTexture()
{
	return wx_materialSection->diffTexture->GetValue().GetString().c_str().AsChar();
}

Color MaterialSection::GetDiffuseColor()
{
	wxVariant colVar = wx_materialSection->diffColor->GetValue();
	wxColor col;
	col << colVar;
	
	Color c = Utils::WxColourToColor(col);

	return c;
}
void MaterialSection::SetDiffuseColor(Color color)
{
	wxVariant colVar;
	
	wxColour col = Utils::ColorToWxColour(color);
	colVar << col;
	wx_materialSection->diffColor->SetValue(colVar);
}

void MaterialSection::SetEmmisive(unsigned int emmisive)
{
	wx_materialSection->emmisive->SetValue(wxVariant((int)emmisive));
}
unsigned int MaterialSection::GetEmmisive()
{
	return wx_materialSection->emmisive->GetValue().GetInteger();
}

void MaterialSection::SetSpecular(unsigned int specular)
{
	wx_materialSection->specular->SetValue(wxVariant((int)specular));
}
unsigned int MaterialSection::GetSpecular()
{
	return wx_materialSection->specular->GetValue().GetInteger();
}

void MaterialSection::SetSpecularIntesity(unsigned int specIntesity)
{
	wx_materialSection->specInt->SetValue(wxVariant((int)specIntesity));
}
unsigned int MaterialSection::GetSpecularIntesity()
{
	return wx_materialSection->specInt->GetValue().GetInteger();
}

void MaterialSection::SetOnChangeCallback(std::function<void(MaterialSectionChange)> callback)
{
	onChangeCallback = callback;
}

void MaterialSection::OnChoiceChange(wxCommandEvent & evt)
{
	if (onChangeCallback)
		onChangeCallback(MSC_SUBSET);
}

void MaterialSection::OnIlluminationChange(wxPropertyGridEvent & evt)
{
	if (onChangeCallback)
		onChangeCallback(MSC_ILLUMINATE);
}

void MaterialSection::OnMaterialChange(wxPropertyGridEvent & evt)
{
	if (onChangeCallback)
	{
		wxString name = evt.GetPropertyName();
		if (name == "UseDiffuse")
		{
			onChangeCallback(MSC_USEDIFFUSE_TEXTURE);
		}
		else if (name == "DiffTexture")
		{
			onChangeCallback(MSC_DIFFUSE_TEXTURE);
		}
		else if (name == "DiffColor")
		{
			onChangeCallback(MSC_DIFFUSE_COLOR);
		}
		else if (name == "UseBump")
		{
			onChangeCallback(MSC_USE_BUMP);
		}
		else if (name == "BumpMap")
		{
			onChangeCallback(MSC_BUMP_TEXTURE);
		}
		else if (name == "Emmisive")
		{
			onChangeCallback(MSC_EMMISIVE);
		}
		else if (name == "Specular")
		{
			onChangeCallback(MSC_SPECULAR);
		}
		else if (name == "SpecIntensity")
		{
			onChangeCallback(MSC_SPECULAR_INTESITY);
		}
	}
}

wxWindow * MaterialSection::GetWXControl()
{
	return wx_materialSection;
}