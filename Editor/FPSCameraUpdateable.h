#pragma once 
#include "FPSCameraController.h"
#include "IEditorUpdateable.h"

class FPSCameraUpdateable : public IEditorUpdateable
{
	FPSCameraController * controller;

public:
	FPSCameraUpdateable(FPSCameraController * cont);
	void Update();
};