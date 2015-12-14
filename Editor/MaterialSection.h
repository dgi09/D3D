#pragma once 

#include "WX_MaterialSection.h"
#include <string>
#include "Color.h"
#include <functional>

enum MaterialSectionChange
{
	MSC_SUBSET = 0,
	MSC_ILLUMINATE,
	MSC_USEDIFFUSE_TEXTURE,
	MSC_USE_BUMP,
	MSC_BUMP_TEXTURE,
	MSC_DIFFUSE_COLOR,
	MSC_DIFFUSE_TEXTURE,
	MSC_EMMISIVE,
	MSC_SPECULAR,
	MSC_SPECULAR_INTESITY
};
class MaterialSection
{
	WX_MaterialSection * wx_materialSection;
	std::function<void(MaterialSectionChange)> onChangeCallback;

public:
	MaterialSection(wxWindow * parent);

	void SetNumberOfSubsets(unsigned int i);
	unsigned int GetCurrentSubset();

	void SetUseDiffuse(bool val);
	bool GetUseDiffuse();
	
	void SetIlluminate(bool val);
	bool GetIlluminate();

	void UseBumpMap(bool val);
	bool GetUseBumpMap();


	std::string GetBumpTexture();
	std::string GetDiffuseTexture();
	
	Color GetDiffuseColor();
	void SetDiffuseColor(Color color);

	void SetEmmisive(unsigned int emmisive);
	unsigned int GetEmmisive();

	void SetSpecular(unsigned int specular);
	unsigned int GetSpecular();

	void SetSpecularIntesity(unsigned int specIntesity);
	unsigned int GetSpecularIntesity();

	void SetOnChangeCallback(std::function<void(MaterialSectionChange)> callback);

	wxWindow * GetWXControl();
private:

	void OnChoiceChange(wxCommandEvent & evt);
	void OnIlluminationChange(wxPropertyGridEvent & evt);
	void OnMaterialChange(wxPropertyGridEvent & evt);

};