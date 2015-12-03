#include "EditorEntity.h"
#include "MainScene.h"
#include <DirectXMath.h>
#include "SelectableObjectsManager.h"

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
	bboxEntity.Get()->SetVisible(!bboxEntity.Get()->IsVisible());
}

void EditorEntity::CreateBBox()
{
	AABB bbox = entityBase->GetBase()->GetAABB();

	Vector3 min = bbox.min;
	Vector3 max = bbox.max;

	StaticVert box[32];
	box[0].pos = Vector3(min.x, max.y, min.z);
	box[1].pos = Vector3(max.x, max.y, min.z);

	box[2].pos = Vector3(max.x, max.y, min.z);
	box[3].pos = Vector3(max.x, min.y, min.z);

	box[4].pos = Vector3(max.x, min.y, min.z);
	box[5].pos = Vector3(min.x, min.y, min.z);

	box[6].pos = Vector3(min.x, min.y, min.z);
	box[7].pos = Vector3(min.x, max.y, min.z);

	box[8].pos = Vector3(min.x, max.y, max.z);
	box[9].pos = Vector3(max.x, max.y, max.z);

	box[10].pos = Vector3(max.x, max.y, max.z);
	box[11].pos = Vector3(max.x, min.y, max.z);

	box[12].pos = Vector3(max.x, min.y, max.z);
	box[13].pos = Vector3(min.x, min.y, max.z);

	box[14].pos = Vector3(min.x, min.y, max.z);
	box[15].pos = Vector3(min.x, max.y, max.z);

	box[16].pos = Vector3(max.x, max.y, min.z);
	box[17].pos = Vector3(max.x, max.y, max.z);

	box[18].pos = Vector3(max.x, max.y, max.z);
	box[19].pos = Vector3(max.x, min.y, max.z);

	box[20].pos = Vector3(max.x, min.y, max.z);
	box[21].pos = Vector3(max.x, min.y, min.z);

	box[22].pos = Vector3(max.x, min.y, min.z);
	box[23].pos = Vector3(max.x, max.y, min.z);

	box[24].pos = Vector3(min.x, max.y, min.z);
	box[25].pos = Vector3(min.x, max.y, max.z);

	box[26].pos = Vector3(min.x, max.y, max.z);
	box[27].pos = Vector3(min.x, min.y, max.z);

	box[28].pos = Vector3(min.x, min.y, max.z);
	box[29].pos = Vector3(min.x, min.y, min.z);

	box[30].pos = Vector3(min.x, min.y, min.z);
	box[31].pos = Vector3(min.x, max.y, min.z);



	ModelCreator<StaticVert> cr;
	cr.StartMesh();
	cr.SetTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	cr.SetDrawMethod(DM_DRAW);
	cr.SetVertexBuffer(box, sizeof(box), sizeof(StaticVert));
	cr.EndMesh();

	bboxEntity = MainScene::Get()->AddStaticEntity(cr, "box"); // to do add number postfix

	StaticEntity * ent = bboxEntity.Get();
	ent->CalculateTransform(false);
	ent->SetTransform(entityBase->GetBase()->GetWorldMatrix());
	Material * mat = ent->GetMaterial(0);

	mat->SetDiffuseColor(Color::Blue());
}