#pragma once 

#include "Common.h"
#include "ConstantBufferPtr.h"
#include "TexturePtr.h"
#include "ConstantBufferPtr.h"
#include "Vector3.h"
#include "BillboardShaderData.h"

class EXPORT DeviceDependableFactory;

class EXPORT BillboardEffectBinder
{

	struct CamVectorsChunk
	{
		Vector3 up;
		float padd1;
		Vector3 right;
		float padd2;
	};


	TexturePtr diffuseTexture;
	ConstantBufferPtr cameraMatrixesBuffer;
	ConstantBufferPtr cameraVectorsBuffer;
	ConstantBufferPtr dataBuffer;
	ID3D11Device * device;

public:
	void SetDevice(ID3D11Device * device);

	void Init(DeviceDependableFactory * factory);
	void Bind();

	void SetDiffuseTexture(TexturePtr ptr);
	void SetCamMatrixesBuffer(ConstantBufferPtr bufferPtr);
	void SetCamVectors(Vector3 upNormal, Vector3 rightNormal);
	void SetBillboardData(BillboardShaderData & data);
};