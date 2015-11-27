#pragma once 
#include "ITest.h"
#include "ParticleSystem.h"
#include "StaticEntity.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "AnimatedEntity.h"
#include <string>
#include "AnimationController.h"
#include "Material.h"
#include <time.h>

class Dragon_Dogs_ParticleSystem : public ITest
{
	ParticleSystemPtr psPtr;
	ParticleSystemPtr drPtr;
	PointLightPtr plDragon;
	int dragonTime;
	bool dragonOn;
	AnimatedEntityPtr enPtr;
	PointLightPtr pointLight;
	StaticEntityPtr planePtr;
	StaticEntityPtr dogPtr;
	StaticEntityPtr dogPtr2;
	float lightChangeTime;
	float powerMin;
	float powerMax;
	AnimationController * animContr;
	StaticEntityPtr torchPtr;
	StaticEntityPtr treePtr;
	StaticEntityPtr swordPtr;


public:
	void Init(Scene * scene);
	void Update();


};