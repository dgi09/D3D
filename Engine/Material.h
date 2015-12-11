#pragma once 
#include "Common.h"
#include "Color.h"
#include "TextureHandler.h"
#include "TexturePtr.h"


class EXPORT EntityBase;
class EXPORT ResourceManager;


struct EXPORT MaterialData
{
	Color diffuseColor;
	unsigned char specularIntesity;
	unsigned char specularPower;
	unsigned char emmisivePowerNorm;
	unsigned char padding1;
	unsigned int optionsMask;
	char padding2[8];
};

class EXPORT Material
{
	TextureHandler diffuseMap;
	TextureHandler bumpMap;
	MaterialData data;

	ResourceManager * resMgr;
public:

	void UseDiffuseMap(bool val);
	bool IsUsingDiffuseMap();

	void SetDiffuseMap(const char * fileName);
	
	void UseBumpMap(bool val);
	bool IsUsingBumpMap();

	void SetBumpMap(const char * fileName);

	void SetDiffuseColor(Color color);
	Color GetDiffuseColor();

	void SetSpecularIntesity(unsigned short val);
	unsigned short GetSpecularIntensity();

	void SetSpecularPower(unsigned short val);
	unsigned short GetSpecularPower();

	void SetEmmisivePower(unsigned short val);
	unsigned short GetEmmisivePower();

private:
	friend class EntityBase;

	void Init(ResourceManager * mgr);
	void FreeResources();
	MaterialData * GetData();
	TexturePtr GetDiffuseTexture();
	TexturePtr GetBumpTexture();
};