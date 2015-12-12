#include "EditorDirectLight.h"
#include "MainScene.h"
#include "Utils.h"
#include "SelectableObjectsManager.h"
#include "ActiveMoveable.h"
#include "PropertiesPanel.h"
#include "ProperySectionsManager.h"


EditorDirectLight::EditorDirectLight(Vector3 pos, Vector3 pointTo)
{
	this->pos = pos;
	this->pointTo = pointTo;
}

void EditorDirectLight::OnAdd()
{

	ptr = MainScene::Get()->AddDirectionalLight();
	ptr.Get()->SetDirection((pointTo - pos).Normalize());
	ptr.Get()->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);

	sphere = MainScene::Get()->AddStaticEntity("assets/sphere.smodel", "sphere");
	StaticEntity * sph = sphere.Get();
	sph->SetPosition(pos);
	sph->SetRotation(0.0f, 0.0f, 0.0f);
	sph->SetScale(5.0f, 5.0f, 5.0f);
	sph->Illuminate(false);

	bbox = Utils::CreateBBoxEntity(sph);
	bbox.Get()->CalculateTransform(false);
	bbox.Get()->SetTransform(sph->GetWorldMatrix());
	Material * mat = bbox.Get()->GetMaterial(0);
	mat->SetDiffuseColor(Color::Blue());

	mat = sph->GetMaterial(0);
	mat->SetDiffuseColor(Color::Red());


	SelectableObjectsManager::GetPtr()->AddElement(this);
	SelectableObjectsManager::GetPtr()->RawSelect(this);

	ActiveMoveable::Set(this);
}
void EditorDirectLight::OnRemove()
{
	Scene * scene = MainScene::Get();
	scene->RemoveStaticEntity(sphere);
	scene->RemoveStaticEntity(bbox);
	scene->RemoveDirectionLight(ptr);
}

bool EditorDirectLight::Select(Vector3 rayOrigin, Vector3 rayDirection)
{
	using namespace DirectX;

	XMFLOAT4X4 mat = sphere.Get()->GetWorldMatrix();

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

	AABB bbox = sphere.Get()->GetAABB();

	return bbox.RayIntersact(org, dir);
}
void EditorDirectLight::OnSelect()
{
	bbox.Get()->SetVisible(true);
	ActiveMoveable::Set(this);

	PropertiesPanel::Clear();


	dlSection = PropertySectionsManager::GetDirectLightSection();

	dlSection->SetDiffuse(ptr.Get()->GetDiffuseAsColor());
	dlSection->SetPosition(pos);
	dlSection->SetPointTo(pointTo);

	dlSection->SetOnChangeCallback(std::bind(&EditorDirectLight::OnDLSectionChange, this, std::placeholders::_1));

	PropertiesPanel::Clear();
	PropertiesPanel::Add(dlSection->GetWXControl());
}
void EditorDirectLight::OnFocusOut()
{
	bbox.Get()->SetVisible(false);
}

void EditorDirectLight::Move(Vector3 offset)
{
	DirectionalLight * p = ptr.Get();
	pos = pos + offset;
	p->SetDirection((pointTo - pos).Normalize());

	sphere.Get()->Move(offset.x, offset.y, offset.z);

	bbox.Get()->SetTransform(sphere.Get()->GetWorldMatrix());
}

void EditorDirectLight::OnDLSectionChange(DirectLightSectionChange ch)
{
	switch(ch)
	{
	case DLSC_POSITION:
	{
		pos = dlSection->GetPosition();
		ptr.Get()->SetDirection((pointTo - pos).Normalize());
		break;
	}
	case DLSC_POINTTO:
	{
		pointTo = dlSection->GetPointTo();
		ptr.Get()->SetDirection((pointTo - pos).Normalize());
		break;
	}
	case DLSC_DIFFUSE:
		ptr.Get()->SetDiffuseColor(dlSection->GetDiffuse());
		break;
	}
}