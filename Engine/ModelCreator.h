#pragma once 
#include "Common.h"
#include <vector>
#include "Vertex.h"
#include <D3D11.h>
#include "MeshRep.h"

class EXPORT ResourceManager;


template <class VertexType>
class EXPORT ModelCreator
{
	std::vector<MeshRep<VertexType>> meshes;

	MeshRep<VertexType> current;


public:


	ModelCreator();

	void StartMesh();
	void EndMesh();

	void SetTopology(D3D11_PRIMITIVE_TOPOLOGY topology);
	void SetDrawMethod(DrawMethod drawMethod);
	void SetVertexBuffer(VertexType * data, unsigned int size ,unsigned int stride);
	void SetIndexBuffer(unsigned int * data, unsigned int numberOfIndecies);

private:
	friend class ResourceManager;

	unsigned int GetNumberOfMeshes();
	MeshRep<VertexType> & GetMeshRep(unsigned int index);
};

template <class VertexType>
ModelCreator<VertexType>::ModelCreator()
{

}

template <class VertexType>
void ModelCreator<VertexType>::StartMesh()
{
	current.indexData = nullptr;
	current.vertData = nullptr;
	current.topology = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
	current.drawMethod = DM_DRAW;
}

template <class VertexType>
void ModelCreator<VertexType>::EndMesh()
{
	meshes.push_back(current);
}

template <class VertexType>
void ModelCreator<VertexType>::SetTopology(D3D11_PRIMITIVE_TOPOLOGY topology)
{
	current.topology = topology;
}

template <class VertexType>
void ModelCreator<VertexType>::SetDrawMethod(DrawMethod drawMethod)
{
	current.drawMethod = drawMethod;
}

template <class VertexType>
void ModelCreator<VertexType>::SetVertexBuffer(VertexType * data, unsigned int size,unsigned int stride)
{
	current.vertData = data;
	current.vertDataSize = size;
	current.vertStride = sizeof(VertexType);
}

template <class VertexType>
void ModelCreator<VertexType>::SetIndexBuffer(unsigned int * data, unsigned int numberOfIndecies)
{
	current.indexData = data;
	current.numberOfIndexes = numberOfIndecies;
}


template <class VertexType>
unsigned int ModelCreator<VertexType>::GetNumberOfMeshes()
{
	return meshes.size();
}

template <class VertexType>
MeshRep<VertexType> & ModelCreator<VertexType>::GetMeshRep(unsigned int index)
{
	return meshes[index];
}