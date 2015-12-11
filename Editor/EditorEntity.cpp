#include "EditorEntity.h"
#include "MainScene.h"
#include <DirectXMath.h>
#include "SelectableObjectsManager.h"
#include "ActiveMoveable.h"
#include "ProperySectionsManager.h"
#include "PropertiesPanel.h"
#include "Utils.h"

using namespace DirectX;

EditorEntity::EditorEntity(IEntity * base)
{
	entityBase = base;
}

void EditorEntity::OnAdd()
{
	CreateBBox();
	bboxEntity.Get()->SetVisible(false);

	SelectableObjectsManager::GetPtr()->AddElement(this);
	SelectableObjectsManager::GetPtr()->RawSelect(this);
}
void EditorEntity::OnRemove()
{
	Scene * scene = MainScene::Get();
	scene->RemoveStaticEntity(bboxEntity);
	
	entityBase->RemoveFromScene(scene);

	SelectableObjectsManager::GetPtr()->RemoveElement(this);
}

bool EditorEntity::Select(Vector3 rayOrigin, Vector3 rayDirection)
{


	XMFLOAT4X4 mat = entityBase->GetBase()->GetWorldMatrix();

	XMMATRIX world = XMLoadFloat4x4((XMFLOAT4X4*)&mat);
	world = XMMatrixTranspose(world);

	XMVECTOR det = XMMatrixDeterminant(world);

	XMMATRIX invWorld = XMMatrixInverse(&det, world);

	Vector3 org = rayOrigin;
	Vector3 dir = rayDirection;

	XMVECTOR orgInv = XMVector3TransformCoord(XMLoadFloat3((XMFLOAT3*)&org), invWorld);
	XMVECTOR dirInv = XMVector3TransformNormal(XMLoadFloat3((XMFLOAT3*)&dir), invWorld);

	dirInv = XMVector3Normalize(dirInv);

	XMStoreFloat3((XMFLOAT3*)&org, orgInv);
	XMStoreFloat3((XMFLOAT3*)&dir, dirInv);

	AABB bbox = entityBase->GetBase()->GetAABB();

	return bbox.RayIntersact(org, dir);
	
}
void EditorEntity::OnSelect()
{
	bboxEntity.Get()->SetVisible(true);
	ActiveMoveable::Set(this);

	EntityBase * base = entityBase->GetBase();

	transformSection = PropertySectionsManager::GetTransformSection();
	transformSection->SetPosition(base->GetPosition());
	transformSection->SetRotation(base->GetRotation());
	transformSection->SetScale(base->GetScale());

	transformSection->SetOnChangeCallback(std::bind(&EditorEntity::OnTransformSectionChange, this, std::placeholders::_1));

	materialSection = PropertySectionsManager::GetMaterialSection();
	materialSection->SetNumberOfSubsets(base->GetNumberOfMaterials());

	Material * mat = base->GetMaterial(0);

	materialSection->SetDiffuseColor(mat->GetDiffuseColor());
	materialSection->SetEmmisive(mat->GetEmmisivePower());
	materialSection->SetIlluminate(base->IsIlluminated());
	materialSection->SetSpecular(mat->GetSpecularPower());
	materialSection->SetSpecularIntesity(mat->GetSpecularIntensity());

	materialSection->SetOnChangeCallback(std::bind(&EditorEntity::OnMaterialSectionChange, this, std::placeholders::_1));

	PropertiesPanel::Clear();
	PropertiesPanel::Add(transformSection->GetWXControl());
	PropertiesPanel::Add(materialSection->GetWXControl());
}

void EditorEntity::OnFocusOut()
{
	bboxEntity.Get()->SetVisible(false);
}
void EditorEntity::CreateBBox()
{
	bboxEntity = Utils::CreateBBoxEntity(entityBase->GetBase());

	StaticEntity * ent = bboxEntity.Get();
	ent->CalculateTransform(false);
	ent->SetTransform(entityBase->GetBase()->GetWorldMatrix());
	Material * mat = ent->GetMaterial(0);

	mat->SetDiffuseColor(Color::Blue());
}

void EditorEntity::Move(Vector3 offset)
{
	entityBase->GetBase()->Move(offset.x, offset.y, offset.z);

	UpdateBBoxTransform();
}

void EditorEntity::OnTransformSectionChange(TransformSectionChange ch)
{
	switch (ch)
	{
	case TSC_POSITION:
		entityBase->GetBase()->SetPosition(transformSection->GetPosition());
		break;
	case TSC_ROTATION:
		entityBase->GetBase()->SetRotation(transformSection->GetRotation());
		break;
	case TSC_SCALE:
		entityBase->GetBase()->SetScale(transformSection->GetScale());
	}

	UpdateBBoxTransform();
}

void EditorEntity::OnMaterialSectionChange(MaterialSectionChange ch)
{
	switch (ch)
	{
	case MSC_SUBSET:
		FillCurrentSubset();
		break;
	case MSC_DIFFUSE_COLOR:
		GetCurrentMat()->SetDiffuseColor(materialSection->GetDiffuseColor());
		break;
	case MSC_USEDIFFUSE_TEXTURE:
	{
		GetCurrentMat()->UseDiffuseMap(materialSection->GetUseDiffuse());
		std::string map = materialSection->GetDiffuseTexture();
		if (!map.empty())
			GetCurrentMat()->SetDiffuseMap(map.c_str());
	}
		break;
	case MSC_DIFFUSE_TEXTURE:
		GetCurrentMat()->SetDiffuseMap(materialSection->GetDiffuseTexture().c_str());
		break;
	case MSC_ILLUMINATE:
		entityBase->GetBase()->Illuminate(materialSection->GetIlluminate());
		break;
	case MSC_EMMISIVE:
		GetCurrentMat()->SetEmmisivePower(materialSection->GetEmmisive());
		break;
	case MSC_SPECULAR:
		GetCurrentMat()->SetSpecularPower(materialSection->GetSpecular());
		break;
	case MSC_SPECULAR_INTESITY:
		GetCurrentMat()->SetSpecularIntesity(materialSection->GetSpecularIntesity());
		break;
	}
}

void EditorEntity::UpdateBBoxTransform()
{
	bboxEntity.Get()->SetTransform(entityBase->GetBase()->GetWorldMatrix());
}

void EditorEntity::FillCurrentSubset()
{
	int subset = materialSection->GetCurrentSubset();

	EntityBase * base = entityBase->GetBase();
	Material * mat = base->GetMaterial(subset);

	materialSection->SetDiffuseColor(mat->GetDiffuseColor());
	materialSection->SetEmmisive(mat->GetEmmisivePower());
	materialSection->SetIlluminate(base->IsIlluminated());
	materialSection->SetSpecular(mat->GetSpecularPower());
	materialSection->SetSpecularIntesity(mat->GetSpecularIntensity());

}

Material * EditorEntity::GetCurrentMat()
{
	return entityBase->GetBase()->GetMaterial(materialSection->GetCurrentSubset());
}