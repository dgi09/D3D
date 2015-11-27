#pragma once
#include "Common.h"
#include <d3d11.h>
#include "DeviceDependable.h"
#include "IDestroyable.h"
#include "Vector3.h"
#include "Constants.h"

enum EXPORT DrawMethod
{
	DM_DRAW = 1,
	DM_DRAW_INDEXED = DM_DRAW << 1,
	DM_DRAW_INSTANCED = DM_DRAW_INDEXED << 1
};


class EXPORT Mesh : public DeviceDependable , public IDestroyable
{
	
	ID3D11Buffer * vertexBuffer;
	ID3D11Buffer * indexBuffer;

	ID3D11Buffer * staging;

	unsigned int numberOfVerts;
	unsigned int numberOfIndecies;
	unsigned int stride;

	D3D11_PRIMITIVE_TOPOLOGY topology;

	unsigned int drawFlag;
public:
	void Init();
	void Destroy();

	void Draw(unsigned int numberOfInstances = 0);
	

	void InitVertexBuffer(unsigned int dataSize, unsigned int stride,void * data);
	void InitIndexBuffer(unsigned int numberIndecies,unsigned int * data);
	
	void SetPrimitveTopology(D3D11_PRIMITIVE_TOPOLOGY topology);
	void SetDrawMethod(unsigned int drawFlag);

	Vector3 * GetPoistions();


	int GetNumberOfVerts();
	int GetStride();

	void * Read();
	void EndRead();
};

