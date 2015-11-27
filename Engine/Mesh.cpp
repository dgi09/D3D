#include "Mesh.h"

void Mesh::Draw(unsigned int numberOfInstances)
{
	ID3D11DeviceContext * context = GetContext();
	unsigned int offset = 0;
	context->IASetVertexBuffers(0,1,&vertexBuffer,&stride,&offset);
	if (indexBuffer)
		context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	context->IASetPrimitiveTopology(topology);

	bool drawInstanced = (drawFlag & DM_DRAW_INSTANCED) == DM_DRAW_INSTANCED;
	bool draw = drawFlag & DM_DRAW == DM_DRAW;
	
	if (drawInstanced)
	{
		if (draw)
			context->DrawInstanced(numberOfVerts, numberOfInstances, 0, 0);
		else
			context->DrawIndexedInstanced(numberOfIndecies, numberOfInstances, 0, 0, 0);
	}
	else
	{
		if (draw)
			context->Draw(numberOfVerts, 0);
		else
			context->DrawIndexed(numberOfIndecies, 0, 0);
	}
}

void Mesh::InitVertexBuffer(unsigned int dataSize, unsigned int stride,void * data)
{

	D3D11_BUFFER_DESC desc;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	desc.ByteWidth = dataSize;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;

	D3D11_SUBRESOURCE_DATA d;
	d.pSysMem = data;

	numberOfVerts = dataSize/stride;
	this->stride = stride;
	HRESULT res = GetDevice()->CreateBuffer(&desc,&d,&vertexBuffer);
}

void Mesh::InitIndexBuffer(unsigned int numberIndecies,unsigned int * data)
{
	D3D11_BUFFER_DESC desc;
	desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	desc.ByteWidth = numberIndecies * 4;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;

	D3D11_SUBRESOURCE_DATA d;
	d.pSysMem = data;

	this->numberOfIndecies = numberIndecies;
	GetDevice()->CreateBuffer(&desc,&d,&indexBuffer);
}


int Mesh::GetNumberOfVerts()
{
	return numberOfVerts;
}

int Mesh::GetStride()
{
	return stride;
}
void * Mesh::Read()
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.ByteWidth = numberOfVerts * stride;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
	desc.MiscFlags = 0;
	desc.Usage = D3D11_USAGE_STAGING;

	HRESULT res = GetDevice()->CreateBuffer(&desc, nullptr, &staging);
	GetContext()->CopyResource(staging, vertexBuffer);

	D3D11_MAPPED_SUBRESOURCE  sub;
	ZeroMemory(&sub,sizeof(D3D11_MAPPED_SUBRESOURCE));
	res = GetContext()->Map(staging,0,D3D11_MAP_READ,0,&sub);
	return sub.pData;
	
}

void Mesh::EndRead()
{
	GetContext()->Unmap(staging,0);
	if (staging)
	{
		staging->Release();
		staging = nullptr;
	}
}

void Mesh::Init()
{
	vertexBuffer = nullptr;
	indexBuffer = nullptr;
	staging = nullptr;
	numberOfVerts = 0;
	numberOfIndecies = 0;
	SetDrawMethod(DM_DRAW);
	SetPrimitveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

}

void Mesh::Destroy()
{
	if(vertexBuffer != nullptr)
		vertexBuffer->Release();

	if(indexBuffer != nullptr)
		indexBuffer->Release();
}


void Mesh::SetPrimitveTopology(D3D11_PRIMITIVE_TOPOLOGY topology)
{
	this->topology = topology;
}

void Mesh::SetDrawMethod(unsigned int drawFlag)
{
	this->drawFlag = drawFlag;
}
