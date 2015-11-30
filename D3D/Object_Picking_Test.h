#pragma once 
#include "ITest.h"
#include "InputManager.h"

class Object_Picking_Test : public ITest
{
	InputManager * input;
	Scene * scene;
	int currentLine;
public:

	void Init(Scene * scene);
	void Update();
	void SetInputMgr(InputManager * mgr);

	void CreateLine(Vector3 begin, Vector3 end);
};