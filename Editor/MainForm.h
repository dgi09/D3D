#pragma once 
#include "WX_MainForm.h"
#include "DrawPanel.h"
#include "FPSCameraController.h"
#include "FPSCameraUpdateable.h"
#include "ArcBallCameraController.h"
#include "ArcBallCameraUpdateable.h"

class MainForm
{
	WX_MainForm * wxForm;
	DrawPanel * drawPanel;
	Scene * scene;

	ArcBallCameraController cameraController;
	ArcBallCameraUpdateable * updateableComponent;
public:

	MainForm();
	void Init();

	void Show();

private:

	void InitScene();

	void DrawPanel_MouseEvent(MouseEvent & evt);
	void DrawPanel_KeyboardEvent(KeyboardEvent & evt);

	void OnAddStaticEntity_Click(wxMouseEvent &evt);

};