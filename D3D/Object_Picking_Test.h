#pragma once 
#include "ITest.h"
#include "InputManager.h"
#include <vector>

struct SceneObj
{
	StaticEntityPtr obj;
	StaticEntityPtr bbox;
};

class Object_Picking_Test : public ITest
{
	InputManager * input;
	Scene * scene;
	int currentBox;

	std::vector<SceneObj> pickable;

public:

	void Init(Scene * scene);
	void Update();
	void SetInputMgr(InputManager * mgr);

	void CreateLine(Vector3 begin, Vector3 end);

	void RunTest(float mX, float mY);

	StaticEntityPtr CreateBBox(StaticEntityPtr ptr);
};