#pragma once 

#include "Scene.h"

class ITest
{
public:
	virtual void Init(Scene * scene) = 0;
	virtual void Update() = 0;
};