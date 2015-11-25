#include <wx/wx.h>
#include "MainForm.h"

class MyApp : public wxApp
{
	MainForm form;
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

	form.Init();
	form.Show();


	return true;
}