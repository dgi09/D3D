#pragma once 
#include "WX_MainForm.h"
#include "DrawPanel.h"


class MainForm
{
	WX_MainForm * wxForm;
	DrawPanel * drawPanel;
	Scene * scene;

public:

	MainForm();
	void Init();

	void Show();

private:

	void InitScene();

	void OnAddStaticEntity_Click(wxMouseEvent &evt);


};