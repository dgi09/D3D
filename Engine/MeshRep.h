#pragma once 

#include "Common.h"
#include "Mesh.h"


template <class VertexType>
struct MeshRep
{
	VertexType * vertData;
	unsigned int vertDataSize;
	unsigned int vertStride;


	unsigned int * indexData;
	unsigned int numberOfIndexes;

	D3D11_PRIMITIVE_TOPOLOGY topology;
	DrawMethod drawMethod;
};