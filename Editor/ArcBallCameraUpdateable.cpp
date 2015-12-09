#include "ArcBallCameraUpdateable.h"

void ArcBallCameraUpdateable::SetController(ArcBallCameraController * controller)
{
	contr = controller;
}

void ArcBallCameraUpdateable::Update()
{
	contr->Update();
}