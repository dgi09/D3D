#include "Billboard_Test.h"
#include "Billboard.h"

void Billboard_Test::Init(Scene * scene)
{
	BillboardPtr ptr = scene->AddBillboard();
	Billboard * b = ptr.Get();
	b->SetSize(20.0f, 20.0f);
	b->UseDiffuseTexture(true);
	b->SetDiffuseTexture("assets/fire.png");

	StaticVert verts[4];

	verts[0].pos = Vector3(-1.0f, -1.0f, 0.0f);
	verts[1].pos = Vector3(-1.0f, 1.0f, 0.0f);
	verts[2].pos = Vector3(1.0f, 1.0f, 0.0f);
	verts[3].pos = Vector3(1.0f, -1.0f, 0.0f);

	verts[0].u = 0.0f;
	verts[0].v = 1.0f;

	verts[1].u = 0.0f;
	verts[1].v = 0.0f;

	verts[2].u = 1.0f;
	verts[2].v = 0.0f;

	verts[3].u = 1.0f;
	verts[3].v = 1.0f;
	unsigned int ind[] = { 0, 1, 3, 1, 3, 2 };

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
	tri->SetPosition(50.0f, 0.0f, 0.0f);
	tri->SetScale(20.0f, 20.0f, 2.0f);

	Material * mat = tri->GetMaterial(0);
	mat->UseDiffuseMap(true);
	mat->SetDiffuseMap("assets/fire.png");
	mat->SetEmmisivePower(1);
}


void Billboard_Test::Update()
{

}