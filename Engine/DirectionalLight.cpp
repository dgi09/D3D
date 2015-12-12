#include "DirectionalLight.h"
#include "DeviceDependableFactory.h"
#include "Texture.h"

void DirectionalLight::Init()
{
	isChanged = true;
	SetDirection(0.0f,0.0f,0.0f);
	SetDiffuseColor(1.0f,1.0f,1.0f,1.0f);
}


void DirectionalLight::SetDirection(Vector3 dir)
{
	if(dir != data->direction)
	{
		data->direction = dir;
		isChanged = true;
	}
	
}

void DirectionalLight::SetDirection(float x,float y,float z)
{
	Vector3 dir;
	dir.x = x;
	dir.y = y;
	dir.z = z;

	SetDirection(dir);
}

void DirectionalLight::SetDiffuseColor(float r,float g,float b,float a)
{
	Vector4 color;
	color.x = r;
	color.y = g;
	color.z = b;
	color.w = a;

	SetDiffuseColor(color);
}

void DirectionalLight::SetDiffuseColor(Vector4 color)
{
	if(data->diffuseColor != color)
	{
		data->diffuseColor = color;
		isChanged = true;
	}
	
}

void DirectionalLight::SetDiffuseColor(Color color)
{
	Vector4 diff;
	diff.x = color.r;
	diff.y = color.g;
	diff.z = color.b;
	diff.w = color.a;

	SetDiffuseColor(diff);
}

bool DirectionalLight::IsChanged()
{
	return isChanged;
}

void DirectionalLight::ChangeApplied()
{
	isChanged = false;
}

void DirectionalLight::SetData(DLData * data)
{
	this->data = data;
}

DirectX::XMFLOAT4X4 DirectionalLight::GetViewProjMatrix()
{
	using namespace DirectX;

	XMVECTOR lookAt = XMVector3Normalize(XMLoadFloat3((const XMFLOAT3*)&data->direction));

	XMVECTOR eyePos = lookAt * -100; 
	XMMATRIX view = XMMatrixTranspose(XMMatrixLookAtLH(eyePos,lookAt,XMVectorSet(0.0f,1.0f,0.0,1.0f)));
	XMMATRIX ortho = XMMatrixTranspose(XMMatrixOrthographicLH(100,100,0.1f,1000.0f));
	XMFLOAT4X4 res;
	XMStoreFloat4x4(&res,view * ortho);

	return res;
}

void DirectionalLight::InitShadowMap(DeviceDependableFactory * factory)
{
	shadowMapPtr = factory->CreateTexture();
	Texture * shadowMap = shadowMapPtr.Get();
	shadowMap->InitTexture(800,800,DEPTH_BUFFER,DXGI_FORMAT_R32G32B32A32_UINT);
}

TexturePtr DirectionalLight::GetShadowMap()
{
	return shadowMapPtr;
}

Vector3 DirectionalLight::GetDirection()
{
	return data->direction;
}
Vector4 DirectionalLight::GetDiffuseAsVector()
{
	return data->diffuseColor;
}

Color DirectionalLight::GetDiffuseAsColor()
{
	Color c;
	c.r = data->diffuseColor.x;
	c.g = data->diffuseColor.y;
	c.b = data->diffuseColor.z;
	c.a = data->diffuseColor.w;

	return c;
}