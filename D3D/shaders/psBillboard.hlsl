
struct VS_OUT
{
	float4 pos : SV_POSITION;
	float4 diffuseColor : COLOR0;
	float2 uv : TEXCOORD;
	float linearDepth : TEXCOORD1;
	uint mode:TEXCOORD2;
};


Texture2D color;
SamplerState samp
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = WRAP;
	AddressV = WRAP;
};

struct PS_OUT
{
	float4 color : SV_TARGET0;
	float4 linDepth : SV_TARGET1;
};

PS_OUT main(VS_OUT input)
{

	PS_OUT output = (PS_OUT)0;
	
	float4 outColor;

	if (input.mode == 1)
	{
		outColor = color.Sample(samp, input.uv);
	}
	else outColor = input.diffuseColor;

	output.color = outColor;
	output.linDepth = input.linearDepth;
	return output;
}