#include "MainForm.h"
#include "CreateEntityDialog.h"


MainForm::MainForm()
{
	wxForm = new WX_MainForm(NULL);
}

void MainForm::Init()
{
	wxPanel * wxDrawPanelHolder = (wxPanel*)wxForm->FindWindowByName(wxString("pnlDraw"));
	wxSizer * pnlSizer = wxDrawPanelHolder->GetSizer();

	drawPanel = new DrawPanel(wxDrawPanelHolder,wxDefaultPosition,wxDrawPanelHolder->GetSize(),wxTAB_TRAVERSAL,wxT("drawPnl111"));
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
	scene->SetShadersPath("E:\\Projects\\D3D\\ShaderTamplates");
	scene->Init();

	CameraPtr camPtr = scene->AddCamera();
	Camera * cam = camPtr.Get();


	cam->SetPosition(0.0f,90.0f,-130.0f);
	cam->LookAt(0.0f,0.0f,0.0f);
	cam->SetNearDistance(2.0f);
	cam->SetFarDistance(1000.0f);
	cam->SetFOV(90.0f);

	scene->SetActiveCamera(camPtr);
}
