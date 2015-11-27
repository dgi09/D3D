#pragma once 

#include "Common.h"
#include "Positionable.h"
#include "SceneDrawable.h"
#include "MeshPtr.h"
#include "BillboardShaderData.h"
#include "TextureHandler.h"


class EXPORT ResourceManager;
class EXPORT BillboardEffectBinder;
class EXPORT Scene;

class EXPORT Billboard : public SceneDrawable
{
	MeshPtr quad;
	BillboardShaderData data;
	TextureHandler diffuseTexture;
	ResourceManager * resMgr;


public:

	void Init(MeshPtr quad, ResourceManager * rMngr);
	void Destroy();

	void SetSize(float width, float height);
	void SetWidth(float width);
	void SetHeight(float height);

	void UseDiffuseTexture(bool val);
	void SetDiffuseColor(Color color);
	void SetDiffuseTexture(char * fileName);

private:
	friend class Scene;

	void Draw(BillboardEffectBinder * binder);


};