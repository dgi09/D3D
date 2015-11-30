#include "Object_Picking_Test.h"
#include "InputManager.h"
#include "ModelCreator.h"

void Object_Picking_Test::Init(Scene * scene)
{
	this->scene = scene;
	currentLine = 0;

	StaticEntityPtr dogPtr2 = scene->AddStaticEntity("assets/dog.smodel", "dog");
	StaticEntity * dog = dogPtr2.Get();

	dog->Illuminate(false);
	dog->SetPosition(0.0f, 0.0, 0.0f);
	dog->SetScale(400.0f, 400.0f, 400.0f);
	dog->SetRotation(0.0f, -60.0f, 180.0f);
	//dog->SetRotationY(45.0f);

	Material * pMat = dog->GetMaterial(0);
	pMat->SetDiffuseColor(Color(1.0, 0.0f, 0.0f, 1.0f));
}

void Object_Picking_Test::Update()
{
	

	

	if (input->MouseButtonClick(B_LEFT))
	{
		CameraPtr camPtr = scene->GetActiveCamera();
		Camera * cam = camPtr.Get();
		cam->CalcPickingRay((float)input->GetMouseX(), (float)input->GetMouseY());
		CreateLine(cam->GetPosition(), cam->GetPickingRayDirection() * 100.0f);
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

	StaticEntityPtr linePtr = scene->AddStaticEntity(modelCreator, "line " + std::to_string(currentLine));

	StaticEntity * line = linePtr.Get();
	line->Illuminate(false);
	Material * mat = line->GetMaterial(0);
	mat->UseDiffuseMap(false);
	mat->SetDiffuseColor(Color::Red());

	currentLine++;
}
