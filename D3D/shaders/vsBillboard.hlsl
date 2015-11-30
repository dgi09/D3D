
struct VS_IN
{
	float3 pos : POSITION;
	float2 uv : TEXCOORD;
};

struct VS_OUT
{
	float4 pos : SV_POSITION;
	float4 diffuseColor : COLOR0;
	float2 uv : TEXCOORD;
	float linearDepth : TEXCOORD1;
	uint mode:TEXCOORD2;
};

cbuffer BillboardData
{
	float3 worldPos;
	float width;
	float4 color;
	float height;
	uint mode;
	float padd1;
	float padd2;
};

cbuffer CameraData
{
	matrix view;
	matrix projection;
};

cbuffer CameraVectors
{
	float3 camUpVector;
	float padding1;

	float3 camRightVector;
	float padding2;
};

VS_OUT main( VS_IN input,uint vI : SV_VertexID)
{

	switch(vI)
	{
	case 0:
		input.pos = -camUpVector * height - camRightVector * width;
		break;
	case 1:
		input.pos = camUpVector * height - camRightVector * width;
		break;
	case 2:
		input.pos = camRightVector * width - camUpVector * height;
		break;
	case 3:
		input.pos = camUpVector * height + camRightVector * width;
		break;
	default:
		break;
	}

	float3 wPos = input.pos + worldPos;
	
	VS_OUT output = (VS_OUT)0;

	output.pos = mul(mul(float4(wPos,1.0f),view),projection);
	output.uv = input.uv;
	
	output.linearDepth = output.pos.z / output.pos.w;
	output.diffuseColor = color;
	output.mode = mode;

	return output;
}


