#pragma once 
#include "WX_MainForm.h"
#include "DrawPanel.h"
#include "FPSCameraController.h"
#include "FPSCameraUpdateable.h"

class MainForm
{
	WX_MainForm * wxForm;
	DrawPanel * drawPanel;
	Scene * scene;

	FPSCameraController cameraController;
	FPSCameraUpdateable * updateableComponent;
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