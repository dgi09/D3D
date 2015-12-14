///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_MaterialSection.h"

///////////////////////////////////////////////////////////////////////////

WX_MaterialSection::WX_MaterialSection( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString cbSubsetsChoices;
	cbSubsets = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, cbSubsetsChoices, 0 );
	cbSubsets->SetSelection( 0 );
	mainSizer->Add( cbSubsets, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	mainSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	propGridIllumination = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_SPLITTER_AUTO_CENTER);
	Illumination = propGridIllumination->Append( new wxPropertyCategory( wxT("Illumination"), wxT("Illumination") ) ); 
	illuminate = propGridIllumination->Append( new wxBoolProperty( wxT("Illuminate"), wxT("Illuminate") ) ); 
	mainSizer->Add( propGridIllumination, 0, wxALL|wxEXPAND, 0 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	mainSizer->Add( m_staticline2, 0, wxEXPAND, 0 );
	
	propGrid = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_SPLITTER_AUTO_CENTER);
	propCategoryMat = propGrid->Append( new wxPropertyCategory( wxT("Material"), wxT("Material") ) ); 
	useDiffuse = propGrid->Append( new wxBoolProperty( wxT("UseDiffuse"), wxT("UseDiffuse") ) ); 
	diffTexture = propGrid->Append( new wxFileProperty( wxT("DiffTexture"), wxT("DiffTexture") ) ); 
	diffColor = propGrid->Append( new wxColourProperty( wxT("DiffColor"), wxT("DiffColor") ) ); 
	useBump = propGrid->Append( new wxBoolProperty( wxT("UseBump"), wxT("UseBump") ) ); 
	bumpMap = propGrid->Append( new wxFileProperty( wxT("BumpMap"), wxT("BumpMap") ) ); 
	emmisive = propGrid->Append( new wxUIntProperty( wxT("Emmisive"), wxT("Emmisive") ) ); 
	specular = propGrid->Append( new wxUIntProperty( wxT("Specular"), wxT("Specular") ) ); 
	specInt = propGrid->Append( new wxFloatProperty( wxT("SpecIntensity"), wxT("SpecIntensity") ) ); 
	mainSizer->Add( propGrid, 1, wxEXPAND, 1 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
}

WX_MaterialSection::~WX_MaterialSection()
{
}
