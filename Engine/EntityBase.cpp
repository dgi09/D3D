#include "EntityBase.h"
#include "BindingSections.h"
#include <DirectXMath.h>
#include "EffectBinder.h"
#include "Mesh.h"
#include "DeviceDependableFactory.h"
#include "ResourceManager.h"

#include "Vertex.h"
#include <cmath>
#include "DrawPack.h"
#include "MaterialBindingSection.h"
#include <cfloat>


using namespace DirectX;


EFFECTMASK EntityBase::GetEffectMask()
{
	return effectMask;
}

void EntityBase::BindEntityData(EffectBinder * binder)
{
	TransformationBindingSection * transforms =(TransformationBindingSection*)binder->GetBindingSectionByFunctionality(TRANSFORMATION);
	transforms->SetWorldMatrix(shaderData.GetWorldMatrixBuffer());

}

void EntityBase::CalculateTransform(bool val)
{
	calcTransform = val;
}

void EntityBase::SetUpShaderData()
{
	if(calcTransform && (isPositionChanged || isRotationChanged || isScaleChanged))
	{
		XMFLOAT3 rotRad;
		rotRad.x = XMConvertToRadians(rotation.x);
		rotRad.y = XMConvertToRadians(rotation.y);
		rotRad.z = XMConvertToRadians(rotation.z);

		XMVECTOR R = XMLoadFloat3((XMFLOAT3*)&rotRad);
		XMVECTOR S = XMLoadFloat3((XMFLOAT3*)&scale);

		XMMATRIX mT = XMMatrixTranslation(position.x,position.y,position.z);
		XMMATRIX mR = XMMatrixRotationRollPitchYawFromVector(R);
		XMMATRIX mS = XMMatrixScalingFromVector(S);

		XMMATRIX res =  XMMatrixTranspose(mS * mR * mT);
		XMStoreFloat4x4(&data.worldMatrix,res);

		shaderData.FillWorldMatrixBuffer(data.worldMatrix);

		isPositionChanged = false;
		isRotationChanged = false;
		isScaleChanged = false;
	}
}

void EntityBase::Draw(EffectBinder * binder)
{

}




void EntityBase::Illuminate(bool val)
{
	if(val)
	{
		EffectMaskUtil::Bind(effectMask,ILLUMINATION);
	}
	else 
	{
		EffectMaskUtil::Unbind(effectMask,ILLUMINATION);
	}
}

void EntityBase::Init(ModelHandler model,ResourceManager * resMgr, DeviceDependableFactory * factory)
{
	Positionable::Positionable();
	Rotateable::Rotateable();
	Scaleable::Scaleable();


	this->modelHandler = model;
	this->resMgr = resMgr;

	materials.resize(model.Get().Get()->GetNumberOfMeshes());

	for(unsigned int i = 0;i < materials.size();i++)
	{
		materials[i].Init(resMgr);
	}

	bSphereCreated = false;
	aabbCreated = false;

	shaderData.Init(factory);

	effectMask = 0;
	EffectMaskUtil::Bind(effectMask,TRANSFORMATION);
	EffectMaskUtil::Bind(effectMask,MATERIAL);

	SetVisible(true);
	CalculateTransform(true);
	Illuminate(false);

}

void EntityBase::Destroy()
{

	for(unsigned int i = 0;i < materials.size();i++)
	{
		materials[i].FreeResources();
	}

	shaderData.Destroy();
	modelHandler.Destroy();

	resMgr = nullptr;
}



void EntityBase::BuildBoundingSphere()
{
	float maxRadius = 0.0f;
	Model * model = modelHandler.Get().Get();

	for(unsigned int i = 0;i < model->GetNumberOfMeshes();i++)
	{
		
		Mesh * mesh = model->GetMeshAt(i).Get();
		
		void * vertData = mesh->Read();
		int stride = mesh->GetStride();

		for(int i = 0;i < mesh->GetNumberOfVerts();i++)
		{
			Vector3 * pos = (Vector3*)((unsigned int)vertData + i * stride);
			float rad = std::sqrt(pos->x * pos->x + pos->y * pos->y + pos->z + pos->z);
			if(rad > maxRadius)
			{
				maxRadius = rad;
			}
		}

		mesh->EndRead();
	}

	bSphere.radius = maxRadius;
	bSphere.position = Vector3(0.0f, 0.0f, 0.0f);
	
	bSphereCreated = true;
}

void EntityBase::BuildAABB()
{
	Vector3 max, min;

	Model * model = modelHandler.Get().Get();

	for (unsigned int i = 0; i < model->GetNumberOfMeshes(); i++)
	{

		Mesh * mesh = model->GetMeshAt(i).Get();

		void * vertData = mesh->Read();
		int stride = mesh->GetStride();
		Vector3 * pos = (Vector3*)((unsigned int)vertData);
		max = *pos;
		min = *pos;

		for (int i = 1; i < mesh->GetNumberOfVerts(); i++)
		{
			pos = (Vector3*)((unsigned int)vertData + i * stride);

			if (pos->x > max.x)
			{
				max.x = pos->x;
			}
			if (pos->y > max.y) max.y = pos->y;
			if (pos->z > max.z) max.z = pos->z;

			if (pos->x < min.x) min.x = pos->x;
			if (pos->y < min.y) min.y = pos->y;
			if (pos->z < min.z) min.z = pos->z;
		}

		mesh->EndRead();
	}

	aabb.max = max;
	aabb.min = min;

	aabbCreated = true;
}

void EntityBase::BindMaterialData(EffectBinder * binder, Material & mat)
{
	if(EffectMaskUtil::IsBinded(effectMask,MATERIAL))
	{
		MaterialBindingSection * section = (MaterialBindingSection*)binder->GetBindingSectionByFunctionality(MATERIAL);
		section->SetDiffuseMap(mat.GetDiffuseTexture());
		section->SetBumpMap(mat.GetBumpTexture());

		section->SetMaterialData(mat.GetData());
	}
}


Material * EntityBase::GetMaterial(unsigned int subset)
{
	return &materials[subset];
}

unsigned int EntityBase::GetNumberOfMaterials()
{
	return materials.size();
}

XMFLOAT4X4 EntityBase::GetWorldMatrix()
{
	SetUpShaderData();

	return data.worldMatrix;
}

BoundingSphere EntityBase::GetBoundingSphere()
{
	if (!bSphereCreated)
		BuildBoundingSphere();

	return bSphere;
}
AABB EntityBase::GetAABB()
{
	if (!aabbCreated)
		BuildAABB();

	return aabb;
}


void EntityBase::SetTransform(DirectX::XMFLOAT4X4 transform)
{
	data.worldMatrix = transform;
	shaderData.FillWorldMatrixBuffer(data.worldMatrix);
}