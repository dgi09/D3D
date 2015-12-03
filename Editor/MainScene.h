#pragma once 
#include "Scene.h"


class MainScene
{
	static Scene * ptr;
public:
	static Scene * Get();
	static void Set(Scene * scene);
};