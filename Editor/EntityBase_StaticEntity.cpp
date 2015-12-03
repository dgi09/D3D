#include "EntityBase_StaticEntity.h"
#include "Scene.h"


EntityBase_StaticEntity::EntityBase_StaticEntity(StaticEntityPtr ptr)
{
	this->ptr = ptr;
}

EntityBase * EntityBase_StaticEntity::GetBase()
{
	return (EntityBase*)ptr.Get();
}

void EntityBase_StaticEntity::RemoveFromScene(Scene * scene)
{
	scene->RemoveStaticEntity(ptr);
}