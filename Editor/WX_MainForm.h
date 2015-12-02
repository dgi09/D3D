///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_MAINFORM_H__
#define __WX_MAINFORM_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WX_MainForm
///////////////////////////////////////////////////////////////////////////////
class WX_MainForm : public wxFrame 
{
	private:
	
	protected:
		wxPanel* pDrawPanel;
		wxNotebook* nbMain;
		wxPanel* pnlCreateBar;
		wxButton* btnCreateStaticEntity;
		wxButton* btnCreateAnimatedEntity;
		wxPanel* pnlPropBar;
	
	public:
		
		WX_MainForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("3dSandbox"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1070,600 ), long style = wxDEFAULT_FRAME_STYLE );
		
		~WX_MainForm();
	
};

#endif //__WX_MAINFORM_H__
