#include "Utils.h"
#include "MainScene.h"

unsigned int Utils::current = 0;
StaticEntityPtr Utils::CreateBBoxEntity(EntityBase * entity)
{
	AABB bbox = entity->GetAABB();

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

	return MainScene::Get()->AddStaticEntity(cr, std::string("box") + std::to_string(current++));
	
}

Color Utils::WxColourToColor(wxColour val)
{
	Color c;
	c.r = (float)val.Red() / 255.0f;
	c.g = (float)val.Green() / 255.0f;
	c.b = (float)val.Blue() / 255.0f;

	return c;
}
wxColour Utils::ColorToWxColour(Color val)
{
	wxColor col;

	unsigned int r = (int)(255.0f * val.r);
	unsigned int g = (int)(255.0f * val.g);
	unsigned int b = (int)(255.0f * val.b);

	col.Set(r, g, b);

	return col;
}