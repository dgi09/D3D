#pragma once 

#include "ArcBallCameraController.h"
#include "IEditorUpdateable.h"

class ArcBallCameraUpdateable : public IEditorUpdateable
{
	ArcBallCameraController * contr;
public:
	void SetController(ArcBallCameraController * controller);
	void Update();
};