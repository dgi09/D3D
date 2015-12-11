#include "EditorPointLight.h"
#include "MainScene.h"
#include "Utils.h"
#include <DirectXMath.h>
#include "ActiveMoveable.h"
#include "SelectableObjectsManager.h"
EditorPointLight::EditorPointLight(PointLightPtr ptr)
{
	this->ptr = ptr;
}

void EditorPointLight::OnAdd()
{
	sphere = MainScene::Get()->AddStaticEntity("assets/sphere.smodel", "sphere");
	StaticEntity * sph = sphere.Get();
	sph->SetPosition(ptr.Get()->GetPosition());
	sph->SetRotation(0.0f, 0.0f, 0.0f);
	sph->SetScale(5.0f, 5.0f, 5.0f);
	sph->Illuminate(false);

	

	bbox = Utils::CreateBBoxEntity(sph);
	bbox.Get()->CalculateTransform(false);
	bbox.Get()->SetTransform(sph->GetWorldMatrix());
	Material * mat = bbox.Get()->GetMaterial(0);
	mat->SetDiffuseColor(Color::Blue());

	SelectableObjectsManager::GetPtr()->AddElement(this);
	SelectableObjectsManager::GetPtr()->RawSelect(this);

	ActiveMoveable::Set(this);

}
void EditorPointLight::OnRemove()
{
	Scene * scene= MainScene::Get();
	scene->RemoveStaticEntity(sphere);
	scene->RemoveStaticEntity(bbox);
	scene->RemovePointLight(ptr);
}

bool EditorPointLight::Select(Vector3 rayOrigin, Vector3 rayDirection)
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
void EditorPointLight::OnSelect()
{
	bbox.Get()->SetVisible(true);
	ActiveMoveable::Set(this);
}
void EditorPointLight::OnFocusOut()
{
	bbox.Get()->SetVisible(false);
}

void EditorPointLight::Move(Vector3 offset)
{
	PointLight * p = ptr.Get();
	Vector3 pos = p->GetPosition();
	p->SetPosition(pos + offset);

	sphere.Get()->Move(offset.x, offset.y, offset.z);

	bbox.Get()->SetTransform(sphere.Get()->GetWorldMatrix());
}