#pragma once 

#include "ITest.h"

class Model_Creator : public ITest
{
public:
	void Init(Scene * scene);
	void Update();
};