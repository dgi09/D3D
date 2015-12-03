#include <wx/wx.h>
#include "MainForm.h"
#include "EditorUpdateableManager.h"
#undef main

class MyApp : public wxApp
{
	MainForm * form;
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	form = new MainForm();

	form->Init();
	form->Show();


	return true;
}


