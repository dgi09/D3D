///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_DirectLightSection.h"

///////////////////////////////////////////////////////////////////////////

WX_DirectLightSection::WX_DirectLightSection( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	propGrid = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_SPLITTER_AUTO_CENTER);
	propCategoryPosition = propGrid->Append( new wxPropertyCategory( wxT("Position"), wxT("Position") ) ); 
	posX = propGrid->Append( new wxFloatProperty( wxT("X"), wxT("X") ) ); 
	posY = propGrid->Append( new wxFloatProperty( wxT("Y"), wxT("Y") ) ); 
	posZ = propGrid->Append( new wxFloatProperty( wxT("Z"), wxT("Z") ) ); 
	pointTo = propGrid->Append( new wxPropertyCategory( wxT("PointTo"), wxT("PointTo") ) ); 
	pointToX = propGrid->Append( new wxFloatProperty( wxT("ToX"), wxT("ToX") ) ); 
	pointToY = propGrid->Append( new wxFloatProperty( wxT("ToY"), wxT("ToY") ) ); 
	pointToZ = propGrid->Append( new wxFloatProperty( wxT("ToZ"), wxT("ToZ") ) ); 
	propCatLight = propGrid->Append( new wxPropertyCategory( wxT("Light"), wxT("Light") ) ); 
	diffuse = propGrid->Append( new wxColourProperty( wxT("Diffuse"), wxT("Diffuse") ) ); 
	mainSizer->Add( propGrid, 1, wxEXPAND, 1 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
}

WX_DirectLightSection::~WX_DirectLightSection()
{
}
