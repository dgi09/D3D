#include "MainForm.h"
#include "CreateEntityDialog.h"
#include "EditorUpdateableManager.h"

MainForm::MainForm()
{
	updateableComponent = new FPSCameraUpdateable(&cameraController);
	EditorUpdateableManager::GetPtr()->AddUpdateable(updateableComponent);


	wxForm = new WX_MainForm(NULL);
}

void MainForm::Init()
{
	wxPanel * wxDrawPanelHolder = (wxPanel*)wxForm->FindWindowByName(wxString("pnlDraw"));
	wxSizer * pnlSizer = wxDrawPanelHolder->GetSizer();

	drawPanel = new DrawPanel(wxDrawPanelHolder,wxDefaultPosition,wxDrawPanelHolder->GetSize(),wxDEFAULT_FRAME_STYLE,wxT("drawPnl111"));
	drawPanel->OnMouseEvent(std::bind(&MainForm::DrawPanel_MouseEvent, this, std::placeholders::_1));
	drawPanel->OnKeyboardEvent(std::bind(&MainForm::DrawPanel_KeyboardEvent, this, std::placeholders::_1));

	pnlSizer->Add(drawPanel->GetWxControl());

	InitScene();

	wxButton * btnAddStaticEntity = (wxButton*)wxForm->FindWindowByName(wxString("btnCreateStaticEntity"));
	btnAddStaticEntity->Bind(wxEVT_LEFT_DOWN,&MainForm::OnAddStaticEntity_Click,this);

}

void MainForm::Show()
{
	wxForm->Show(true);
}

void MainForm::OnAddStaticEntity_Click(wxMouseEvent &evt)
{
	CreateEntityDialog dialog;
	dialog.Show();
	DialogResult res = dialog.GetResult();

	if(res == OK)
	{

		AnimatedEntityPtr enPtr = scene->AddAnimatedEntity(dialog.GetFilePath(),dialog.GetName());
		AnimatedEntity * en = enPtr.Get();
		en->SetPosition(0.0f,0.0f,0.0f);
		en->Illuminate(false);
		en->SetScale(10.0f,10.0f,10.0f);
		en->SetRotationY(90.0f);

		Material * mat = en->GetMaterial(0);
		mat->UseDiffuseMap(false);
		mat->SetDiffuseColor(Color::Red());

		mat->SetEmmisivePower(6);
		mat->SetSpecularPower(240);
		mat->SetSpecularIntesity(5);
	}

}



void MainForm::InitScene()
{
	scene = drawPanel->GetScene();
#ifdef WORK_PC
	scene->SetShadersPath("E:\\D3D\\ShaderTamplates");
#else
	scene->SetShadersPath("E:\\Projects\\D3D\\ShaderTamplates");
#endif
	scene->Init();
	scene->SetGlobalAmbient(0.03f, 0.03f, 0.03f, 1.0f);
	scene->SetBackgroundColor(Color::Blue());


	CameraPtr camPtr = scene->AddCamera();
	Camera * cam = camPtr.Get();


	cam->SetPosition(0.0f,90.0f,-130.0f);
	cam->LookAt(0.0f,0.0f,0.0f);
	cam->SetNearDistance(2.0f);
	cam->SetFarDistance(1000.0f);
	cam->SetFOV(90.0f);

	scene->SetActiveCamera(camPtr);


	cameraController.SetCamera(camPtr);
	cameraController.SetMovementSpeed(2.0f);
}

void MainForm::DrawPanel_MouseEvent(MouseEvent & evt)
{
	if (evt.type == MET_BUTTONDOWN)
	{
		if (evt.button == ME_MB_RIGHT)
		{
			cameraController.InjectMouseDown(FPSBind_Mouse_Right);
		}
	}

	if (evt.type == MET_BUTTONUP)
	{
		if (evt.button == ME_MB_RIGHT)
		{
			cameraController.InjectMouseUp(FPSBind_Mouse_Right);
		}
	}

	if (evt.type == MET_MOTION)
	{
		cameraController.InjectMouseMove(true);
	}
	else cameraController.InjectMouseMove(false);

	cameraController.InjectMousePos(evt.x, evt.y);
}

void MainForm::DrawPanel_KeyboardEvent(KeyboardEvent & evt)
{
	if (evt.type == KET_KEYDOWN)
	{
		if (evt.keyCode == WXK_LEFT)
			cameraController.InjectKeyDown(FPSBind_Key_Left);
		else 
		if (evt.keyCode == WXK_RIGHT)
			cameraController.InjectKeyDown(FPSBind_Key_Right);
		else 
		if (evt.keyCode == WXK_UP)
			cameraController.InjectKeyDown(FPSBind_Key_Up);
		else
		if (evt.keyCode == WXK_DOWN)
			cameraController.InjectKeyDown(FPSBind_Key_Down);
	}

	if (evt.type == KET_KEYUP)
	{
		if (evt.keyCode == WXK_LEFT)
			cameraController.InjectKeyUp(FPSBind_Key_Left);
		else
			if (evt.keyCode == WXK_RIGHT)
				cameraController.InjectKeyUp(FPSBind_Key_Right);
			else
				if (evt.keyCode == WXK_UP)
					cameraController.InjectKeyUp(FPSBind_Key_Up);
				else
					if (evt.keyCode == WXK_DOWN)
						cameraController.InjectKeyUp(FPSBind_Key_Down);
	}
}
