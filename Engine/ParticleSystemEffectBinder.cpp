#include "ParticleSystemEffectBinder.h"
#include "ParticleSystemsInfo.h"
#include "ConstantBuffer.h"
#include "ParticleGPUData.h"
#include "D3D11.h"


void ParticleSystemEffectBinder::Init(DeviceDependableFactory * factory)
{
	colorTexture = TexturePtr(true);
	dataBuffer = factory->CreateConstantBuffer();
	ConstantBuffer * b = dataBuffer.Get();

	b->InitBuffer(sizeof(ParticleGPUData) * MAX_PARTICLES_IN_SYSTEM);

	cameraVectorsBuffer = factory->CreateConstantBuffer();
	b = cameraVectorsBuffer.Get();

	b->InitBuffer(sizeof(CameraVectorsChunck));
	camVectorsChunck.padding1 = 0;
	camVectorsChunck.padding2 = 0;

}

void ParticleSystemEffectBinder::Destroy()
{
	dataBuffer.Delete();
	cameraVectorsBuffer.Delete();
}

void ParticleSystemEffectBinder::Bind()
{
	ID3D11DeviceContext * context = GetContext();
	ID3D11ShaderResourceView * textureSRV = colorTexture.Get()->GetShaderResourcePointer();
	ID3D11Buffer * buffers[3] = {cameraBuffer.Get()->GetBufferPointer(),cameraVectorsBuffer.Get()->GetBufferPointer(),dataBuffer.Get()->GetBufferPointer()};

	context->VSSetConstantBuffers(0,3,buffers);
	context->PSSetShaderResources(0,1,&textureSRV);
}

void ParticleSystemEffectBinder::SetColorTexture(TexturePtr texture)
{
	colorTexture = texture;
}

void ParticleSystemEffectBinder::SetCameraBuffer(ConstantBufferPtr buffer)
{
	cameraBuffer = buffer;
}

void ParticleSystemEffectBinder::FillParticleData(void * data,unsigned int size)
{
	dataBuffer.Get()->FillBuffer(data,size);
}




void ParticleSystemEffectBinder::SetCameraVectors(Vector3 upNormal,Vector3 rightNormal)
{
	camVectorsChunck.right = rightNormal;
	camVectorsChunck.up = upNormal;

	cameraVectorsBuffer.Get()->FillBuffer(&camVectorsChunck);
}
