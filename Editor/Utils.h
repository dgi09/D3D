#pragma once 
#include "Scene.h"

class Utils
{
	static unsigned int current;
public:
	static StaticEntityPtr CreateBBoxEntity(EntityBase * entity);
};