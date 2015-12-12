///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_PointLightSection.h"

///////////////////////////////////////////////////////////////////////////

WX_PointLightSection::WX_PointLightSection( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	propGrid = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_SPLITTER_AUTO_CENTER);
	propCategoryPos = propGrid->Append( new wxPropertyCategory( wxT("Position"), wxT("Position") ) ); 
	posX = propGrid->Append( new wxFloatProperty( wxT("X"), wxT("X") ) ); 
	posY = propGrid->Append( new wxFloatProperty( wxT("Y"), wxT("Y") ) ); 
	posZ = propGrid->Append( new wxFloatProperty( wxT("Z"), wxT("Z") ) ); 
	propCategoryLight = propGrid->Append( new wxPropertyCategory( wxT("Light"), wxT("Light") ) ); 
	Diffuse = propGrid->Append( new wxColourProperty( wxT("Diffuse"), wxT("Diffuse") ) ); 
	Range = propGrid->Append( new wxFloatProperty( wxT("Range"), wxT("Range") ) ); 
	mainSizer->Add( propGrid, 1, wxEXPAND, 1 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
}

WX_PointLightSection::~WX_PointLightSection()
{
}
