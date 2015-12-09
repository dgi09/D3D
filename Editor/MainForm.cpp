#include "MainForm.h"
#include "CreateEntityDialog.h"
#include "EditorUpdateableManager.h"
#include "EditorEntity.h"
#include "EntityBase_StaticEntity.h"
#include "EditorSceneObjectsManager.h"
#include "MainScene.h"
#include "SelectableObjectsManager.h"
#include "ActiveTool.h"
#include "SelectTool.h"
#include "MoveTool.h"

MainForm::MainForm()
{
	updateableComponent = new ArcBallCameraUpdateable();
	updateableComponent->SetController(&cameraController);

	EditorUpdateableManager::GetPtr()->AddElement(updateableComponent);
	ActiveTool::Set(new SelectTool());


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

		StaticEntityPtr enPtr = scene->AddStaticEntity(dialog.GetFilePath(),dialog.GetName());
		StaticEntity * en = enPtr.Get();
		en->SetPosition(10.0f,10.0f,0.0f);
		en->Illuminate(false);
		en->SetScale(10.0f,10.0f,10.0f);
		en->SetRotationY(90.0f);

		for (unsigned int i = 0; i < en->GetNumberOfMaterials(); i++)
		{
			Material * mat = en->GetMaterial(i);
			mat->UseDiffuseMap(false);
			mat->SetDiffuseColor(Color::Red());

			mat->SetEmmisivePower(6);
			mat->SetSpecularPower(240);
			mat->SetSpecularIntesity(5);
		}
		


		EditorEntity * entity = new EditorEntity(new EntityBase_StaticEntity(enPtr));
		EditorSceneObjectsManager::GetPtr()->AddElement(entity);

		ActiveTool::Set(new SelectTool);
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

	MainScene::Set(scene);
	
	CameraPtr camPtr = scene->AddCamera();
	Camera * cam = camPtr.Get();


	cam->SetPosition(0.0f,90.0f,-130.0f);
	cam->LookAt(0.0f,0.0f,0.0f);
	cam->SetNearDistance(2.0f);
	cam->SetFarDistance(10000.0f);
	cam->SetFOV(45.0f);

	scene->SetActiveCamera(camPtr);


	cameraController.SetCamera(camPtr);
	cameraController.SetMoveAmount(2.0f);
	cameraController.SetZoomAmount(10.0f);
	cameraController.SetRotateAmount(3.0f);

}

void MainForm::DrawPanel_MouseEvent(MouseEvent & evt)
{
	if (evt.type == MET_BUTTONDOWN)
	{
		if (evt.button == ME_MB_RIGHT)
		{
			cameraController.InjectRightMouseButtonDown();
		}
	}

	if (evt.type == MET_BUTTONUP)
	{
		if (evt.button == ME_MB_RIGHT)
		{
			cameraController.InjectRightMouseButtonUp();
		}
	}

	if (evt.type == MET_WHEEL)
	{
		cameraController.InjectScroll(true);
		cameraController.InjectVerticalScroll(evt.vertScroll);

	}


	cameraController.InjectMouseMove(evt.type == MET_MOTION);

	cameraController.InjectMousePos(evt.x, evt.y);


	ActiveTool::OnMouseEvent(evt);
	
}

void MainForm::DrawPanel_KeyboardEvent(KeyboardEvent & evt)
{
	if (evt.type == KET_KEYDOWN)
	{
		if (evt.keyCode == WXK_CONTROL)
			cameraController.InjectCtrKeyDown();
	
	}

	if (evt.type == KET_KEYUP)
	{
		if (evt.keyCode == WXK_CONTROL)
			cameraController.InjectCtrKeyUp();
	

		if (evt.keyCode == 'W')
		{
			ActiveTool::Set(new MoveTool());
		}

		if (evt.keyCode == 'S')
		{
			ActiveTool::Set(new SelectTool());
		}
	}

	

	ActiveTool::OnKeyboardEvent(evt);
}
