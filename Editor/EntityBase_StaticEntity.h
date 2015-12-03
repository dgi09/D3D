#pragma once 
#include "IEntity.h"
#include "Scene.h"


class EntityBase_StaticEntity : public IEntity
{
	StaticEntityPtr ptr;
public:
	EntityBase_StaticEntity(StaticEntityPtr ptr);
	EntityBase * GetBase();

	void RemoveFromScene(Scene * scene);
};