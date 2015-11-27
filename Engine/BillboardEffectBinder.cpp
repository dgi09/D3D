#include "BillboardEffectBinder.h"
#include "DeviceDependableFactory.h"
#include "ConstantBuffer.h"


void BillboardEffectBinder::Init(DeviceDependableFactory * factory)
{
	diffuseTexture = TexturePtr(true);
	cameraVectorsBuffer = factory->CreateConstantBuffer();
	
	ConstantBuffer * buff = cameraVectorsBuffer.Get();
	buff->InitBuffer(sizeof(CamVectorsChunk));

	dataBuffer = factory->CreateConstantBuffer();
	buff = dataBuffer.Get();
	buff->InitBuffer(sizeof(BillboardShaderData));
}

void BillboardEffectBinder::SetDevice(ID3D11Device * device)
{
	this->device = device;
}

void BillboardEffectBinder::Bind()
{
	ID3D11DeviceContext * ic;
	device->GetImmediateContext(&ic);

	ID3D11Buffer * b1 = dataBuffer.Get()->GetBufferPointer();
	ID3D11Buffer * b2 = cameraMatrixesBuffer.Get()->GetBufferPointer();
	ID3D11Buffer * b3 = cameraVectorsBuffer.Get()->GetBufferPointer();


	ID3D11Buffer * buffers[3] = {b1,b2,b3};
	ic->VSSetConstantBuffers(0, 3, buffers);

	if (!diffuseTexture.IsNull())
	{
		ID3D11ShaderResourceView * textureSrv = diffuseTexture.Get()->GetShaderResourcePointer();
		ic->PSSetShaderResources(0, 1, &textureSrv);
	}


}

void BillboardEffectBinder::SetCamMatrixesBuffer(ConstantBufferPtr bufferPtr)
{
	cameraMatrixesBuffer = bufferPtr;
}
void BillboardEffectBinder::SetCamVectors(Vector3 upNormal, Vector3 rightNormal)
{
	CamVectorsChunk ch;
	ch.up = upNormal;
	ch.right = rightNormal;

	cameraVectorsBuffer.Get()->FillBuffer(&ch);
}
void BillboardEffectBinder::SetBillboardData(BillboardShaderData & data)
{
	dataBuffer.Get()->FillBuffer(&data);
}

void BillboardEffectBinder::SetDiffuseTexture(TexturePtr ptr)
{
	diffuseTexture = ptr;
}