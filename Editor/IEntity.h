#pragma once 
#include "EntityBase.h"

class Scene;

class IEntity
{
public:
	virtual EntityBase * GetBase() = 0;
	virtual void RemoveFromScene(Scene * scene) = 0;
};