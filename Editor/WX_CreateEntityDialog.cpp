///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_CreateEntityDialog.h"

///////////////////////////////////////////////////////////////////////////

WX_CreateEntityDialog::WX_CreateEntityDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bsMain;
	bsMain = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Name :     "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	txtName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("txtName") );
	bSizer5->Add( txtName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bsMain->Add( bSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 1 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("FileName : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );
	
	fpckFileName = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE, wxDefaultValidator, wxT("flpcFileName") );
	bSizer6->Add( fpckFileName, 0, wxALL, 0 );
	
	
	bsMain->Add( bSizer6, 0, 0, 1 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bsMain->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );
	
	btnOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("btnOK") );
	bSizer7->Add( btnOK, 0, wxALL, 5 );
	
	btnCancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("btnCancel") );
	bSizer7->Add( btnCancel, 0, wxALL, 5 );
	
	
	bsMain->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bsMain );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btnOK->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WX_CreateEntityDialog::OnOKClicked ), NULL, this );
	btnCancel->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WX_CreateEntityDialog::OnCancelClicked ), NULL, this );
}

WX_CreateEntityDialog::~WX_CreateEntityDialog()
{
	// Disconnect Events
	btnOK->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WX_CreateEntityDialog::OnOKClicked ), NULL, this );
	btnCancel->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( WX_CreateEntityDialog::OnCancelClicked ), NULL, this );
	
}

void WX_CreateEntityDialog::OnOKClicked(wxMouseEvent& event)
{
	EndDialog(wxID_OK);
}

void WX_CreateEntityDialog::OnCancelClicked(wxMouseEvent& event)
{
	EndDialog(wxID_CANCEL);
}
