///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_MainForm.h"

///////////////////////////////////////////////////////////////////////////

WX_MainForm::WX_MainForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bsMain;
	bsMain = new wxBoxSizer( wxHORIZONTAL );
	
	pDrawPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 900,600 ), wxTAB_TRAVERSAL, wxT("pnlDraw") );
	wxBoxSizer* bsDrawPanel;
	bsDrawPanel = new wxBoxSizer( wxVERTICAL );
	
	bsDrawPanel->SetMinSize( wxSize( 900,600 ) ); 
	
	pDrawPanel->SetSizer( bsDrawPanel );
	pDrawPanel->Layout();
	bsMain->Add( pDrawPanel, 0, wxALL, 1 );
	
	nbMain = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	pnlCreateBar = new wxPanel( nbMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bMain;
	bMain = new wxBoxSizer( wxVERTICAL );
	
	btnCreateStaticEntity = new wxButton( pnlCreateBar, wxID_ANY, wxT("Static Entity"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("btnCreateStaticEntity") );
	bMain->Add( btnCreateStaticEntity, 0, wxALL|wxEXPAND, 3 );
	
	btnCreateAnimatedEntity = new wxButton( pnlCreateBar, wxID_ANY, wxT("Animated Entity"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("btnCreateAnimatedEntity") );
	bMain->Add( btnCreateAnimatedEntity, 0, wxALL|wxEXPAND, 3 );
	
	
	pnlCreateBar->SetSizer( bMain );
	pnlCreateBar->Layout();
	bMain->Fit( pnlCreateBar );
	nbMain->AddPage( pnlCreateBar, wxT("Create Object"), true );
	pnlPropBar = new wxPanel( nbMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, wxT("pnlPropBar") );
	wxBoxSizer* pnlPropSizer;
	pnlPropSizer = new wxBoxSizer( wxVERTICAL );
	
	
	pnlPropBar->SetSizer( pnlPropSizer );
	pnlPropBar->Layout();
	pnlPropSizer->Fit( pnlPropBar );
	nbMain->AddPage( pnlPropBar, wxT("Properties"), false );
	
	bsMain->Add( nbMain, 1, wxEXPAND, 1 );
	
	
	this->SetSizer( bsMain );
	this->Layout();
	
	this->Centre( wxBOTH );
}

WX_MainForm::~WX_MainForm()
{
}
