#include "FPSCameraUpdateable.h"

FPSCameraUpdateable::FPSCameraUpdateable(FPSCameraController * cont)
{
	controller = cont;
}
void FPSCameraUpdateable::Update()
{
	controller->Update();
}