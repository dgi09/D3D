#include "Object_Picking_Test.h"
#include "InputManager.h"
#include "ModelCreator.h"
#include <DirectXMath.h>
#include "ModelCreator.h"
#include <stdio.h>

void Object_Picking_Test::Init(Scene * scene)
{
	this->scene = scene;
	currentBox = 0;

	StaticEntityPtr dogPtr2 = scene->AddStaticEntity("assets/sphere.smodel", "dog");
	StaticEntityPtr dogBBox = CreateBBox(dogPtr2);

	SceneObj obj;
	obj.obj = dogPtr2;
	obj.bbox = dogBBox;

	pickable.push_back(obj);

	StaticEntity * dog = dogPtr2.Get();

	dog->Illuminate(false);
	dog->SetPosition(0.0f, 0.0, 0.0f);
	dog->SetScale(100.0f, 100.0f, 100.0f);
	dogBBox.Get()->SetScale(100.0f, 100.0f, 100.0f);
	//dogBBox.Get()->CalculateTransform(false);

	
	DirectX::XMFLOAT4X4 dogMat = dog->GetWorldMatrix();

	dogBBox.Get()->CalculateTransform(false);
	dogBBox.Get()->SetTransform(dogMat);

	DirectX::XMFLOAT4X4 boxMat = dogBBox.Get()->GetWorldMatrix();

	//dog->SetRotation(0.0f, -60.0f, 180.0f);
	//dog->SetRotationY(45.0f);

	Material * pMat = dog->GetMaterial(0);
	pMat->SetDiffuseColor(Color(1.0, 0.0f, 0.0f, 1.0f));
}

void Object_Picking_Test::Update()
{
	if (input->MouseButtonClick(B_LEFT))
	{
		printf("Click  X: %i Y: %i \n", input->GetMouseX(), input->GetMouseY());
		RunTest((float)input->GetMouseX(), (float)input->GetMouseY());
	}
}

void Object_Picking_Test::SetInputMgr(InputManager * mgr)
{
	input = mgr;
}

void Object_Picking_Test::CreateLine(Vector3 begin, Vector3 end)
{
	StaticVert verts[2];
	verts[0].pos = begin;
	verts[1].pos = end;

	ModelCreator<StaticVert> modelCreator;
	modelCreator.StartMesh();
	modelCreator.SetDrawMethod(DM_DRAW);
	modelCreator.SetTopology(D3D10_PRIMITIVE_TOPOLOGY_LINELIST);
	modelCreator.SetVertexBuffer(verts, sizeof(verts), sizeof(StaticVert));
	modelCreator.EndMesh();

	StaticEntityPtr linePtr = scene->AddStaticEntity(modelCreator, "line " + std::to_string(currentBox));

	StaticEntity * line = linePtr.Get();
	line->Illuminate(false);
	Material * mat = line->GetMaterial(0);
	mat->UseDiffuseMap(false);
	mat->SetDiffuseColor(Color::Red());

	currentBox++;
}

void Object_Picking_Test::RunTest(float mX, float mY)
{
	CameraPtr ptr = scene->GetActiveCamera();
	Camera * cam = ptr.Get();
	cam->CalcPickingRay(mX, mY);

	using namespace DirectX;


	for (unsigned int i = 0; i < pickable.size(); i++)
	{
		SceneObj obj = pickable[i];
		StaticEntity * ent = obj.obj.Get();
		
		XMFLOAT4X4 mat = ent->GetWorldMatrix();

		XMMATRIX world = XMLoadFloat4x4((XMFLOAT4X4*)&mat);
		XMVECTOR det = XMMatrixDeterminant(world);

		XMMATRIX invWorld = XMMatrixInverse(&det, world);

		Vector3 org = cam->GetPosition();
		Vector3 dir = cam->GetPickingRayDirection();

		XMVECTOR orgInv = XMVector3TransformCoord(XMLoadFloat3((XMFLOAT3*)&org), invWorld);
		XMVECTOR dirInv = XMVector3TransformNormal(XMLoadFloat3((XMFLOAT3*)&dir), invWorld);

		dirInv = XMVector3Normalize(dirInv);

		XMStoreFloat3((XMFLOAT3*)&org, orgInv);
		XMStoreFloat3((XMFLOAT3*)&dir, dirInv);

		AABB bbox = ent->GetAABB();
		if (bbox.RayIntersact(org, dir))
		{
			obj.bbox.Get()->SetVisible(!obj.bbox.Get()->IsVisible());
		}

	}
}

StaticEntityPtr Object_Picking_Test::CreateBBox(StaticEntityPtr ptr)
{
	AABB bbox = ptr.Get()->GetAABB();
	
	Vector3 min = bbox.min;
	Vector3 max = bbox.max;

	StaticVert box[32];
	box[0].pos = Vector3(min.x, max.y, min.z);
	box[1].pos = Vector3(max.x, max.y, min.z);

	box[2].pos = Vector3(max.x, max.y, min.z);
	box[3].pos = Vector3(max.x, min.y, min.z);
	
	box[4].pos = Vector3(max.x, min.y, min.z);
	box[5].pos = Vector3(min.x,min.y,min.z);

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

	StaticEntityPtr boxPtr = scene->AddStaticEntity(cr, "box" + std::to_string(currentBox));

	StaticEntity * ent = boxPtr.Get();
	Material * mat = ent->GetMaterial(0);

	mat->SetDiffuseColor(Color::Blue());

	currentBox++;

	return boxPtr;
}
