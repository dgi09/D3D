///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_CREATEENTITYDIALOG_H__
#define __WX_CREATEENTITYDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WX_CreateEntityDialog
///////////////////////////////////////////////////////////////////////////////
class WX_CreateEntityDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* txtName;
		wxStaticText* m_staticText2;
		wxFilePickerCtrl* fpckFileName;
		wxStaticLine* m_staticline1;
		wxButton* btnOK;
		wxButton* btnCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOKClicked( wxMouseEvent& event );
		virtual void OnCancelClicked( wxMouseEvent& event );
		
	
	public:
		
		WX_CreateEntityDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create  Entity"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 290,136 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~WX_CreateEntityDialog();
	
};

#endif //__WX_CREATEENTITYDIALOG_H__
