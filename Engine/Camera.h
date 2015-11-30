#pragma once
#include "Common.h"
#include "Positionable.h"
#include "CameraData.h"
#include "Vector3.h"
#include "Frustrum.h"


class EXPORT Scene;

class EXPORT Camera : public Positionable
{
	Vector3 lookAt;
	bool requireViewMatrixRecalculation;
	bool requirePorjMatrixRecalculation;

	CameraData shaderData;

	float nearDistance;
	float farDistance;
	float aspectRatio;
	float fov;
	float width;
	float height;

	bool isChanged;

	Frustrum frustrum;

	Vector3 upNormal;
	Vector3 rightNormal;

	Vector3 pickRayOrigin;
	Vector3 pickRayDirection;
public:
	
	void LookAt(float x,float y,float z);
	void LookAt(Vector3 val);

	void SetNearDistance(float val);
	void SetFarDistance(float val);
	void SetFOV(float val);
	void SetAspectRatio(float val);
	void SetViewport(float width, float height);

	Vector3 GetLookDirection();
	Vector3 GetLookAt();

	void CalcVectors();

	Vector3 GetUpNormal();
	Vector3 GetRightNormal();

	void CalcPickingRay(float localX, float localY);
	Vector3 GetPickingRayOrigin();
	Vector3 GetPickingRayDirection();
protected:
	void SetUpData();

	friend class Scene;

	CameraData * GetData();
	void Init();
	bool IsChanged();
	void ChangeApplied();

	void CalcFrustrum();
	Frustrum * GetFrustrum();

};