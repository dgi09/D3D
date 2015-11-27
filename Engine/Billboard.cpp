#include "Billboard.h"
#include "BillboardEffectBinder.h"
#include "ResourceManager.h"

void Billboard::Init(MeshPtr quad, ResourceManager * rMngr)
{
	this->quad = quad;
	resMgr = rMngr;
	UseDiffuseTexture(false);
	SetDiffuseColor(Color::White());

	diffuseTexture = TextureHandler(false);
}

void Billboard::Destroy()
{
	if (diffuseTexture.ContainsObject())
	{
		diffuseTexture.Destroy();
	}
}

void Billboard::SetSize(float width, float height)
{
	SetWidth(width);
	SetHeight(height);
}

void Billboard::SetWidth(float width)
{
	data.width = width;
}
void Billboard::SetHeight(float height)
{
	data.height = height;

}

void Billboard::UseDiffuseTexture(bool val)
{
	if (val)
	{
		data.mode = 1;
	}
	else
		data.mode = 0;
}
void Billboard::SetDiffuseColor(Color color)
{
	data.difuseColor = color;
}

void Billboard::Draw(BillboardEffectBinder * binder)
{
	if (data.mode == 1)
	{
		binder->SetDiffuseTexture(diffuseTexture.Get());
	}

	data.pos = GetPosition();
	binder->SetBillboardData(data);
	binder->Bind();


	quad.Get()->SetDrawMethod(DM_DRAW);

	quad.Get()->Draw();
}

void Billboard::SetDiffuseTexture(char * fileName)
{
	diffuseTexture = resMgr->GetTexture(fileName);
}