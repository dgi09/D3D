#include "Model_Creator.h"
#include "StaticEntity.h"
#include "ModelCreator.h"
#include "Material.h"


void Model_Creator::Init(Scene * scene)
{
	StaticVert verts[4];

	verts[0].pos = Vector3(-10.0f, -10.0f, 0.0f);
	verts[1].pos = Vector3(-10.0f, 10.0f, 0.0f);
	verts[2].pos = Vector3(10.0f, 10.0f, 0.0f);
	verts[3].pos = Vector3(10.0f, -10.0f, 0.0f);

	verts[0].u = 0.0f;
	verts[0].v = 1.0f;

	verts[1].u = 0.0f;
	verts[1].v = 0.0f;

	verts[2].u = 1.0f;
	verts[2].v = 0.0f;

	verts[3].u = 1.0f;
	verts[3].v = 1.0f;
	unsigned int ind[] = { 0, 1, 2, 0, 2, 3 };

	ModelCreator<StaticVert> creator;
	creator.StartMesh();
	creator.SetTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	creator.SetDrawMethod(DM_DRAW_INDEXED);
	creator.SetVertexBuffer(verts, sizeof(verts), sizeof(StaticVert));
	creator.SetIndexBuffer(ind, 6);
	creator.EndMesh();

	StaticEntityPtr triPtr = scene->AddStaticEntity(creator, "tri");
	StaticEntity * tri = triPtr.Get();
	tri->Illuminate(false);
	tri->SetPosition(0.0f, 0.0f, 0.0f);
	tri->SetScale(3.0f, 3.0f, 3.0f);

	Material * mat = tri->GetMaterial(0);
	mat->UseDiffuseMap(true);
	mat->SetDiffuseMap("assets/fire.png");
	mat->SetEmmisivePower(1);
}

void Model_Creator::Update()
{

}