///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WX_TransformSection.h"

///////////////////////////////////////////////////////////////////////////

WX_TransformSection::WX_TransformSection( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	propGrid = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_SPLITTER_AUTO_CENTER);
	propCategoryPos = propGrid->Append( new wxPropertyCategory( wxT("Position"), wxT("Position") ) ); 
	itemPosX = propGrid->Append( new wxFloatProperty( wxT("X"), wxT("X") ) ); 
	posY = propGrid->Append( new wxFloatProperty( wxT("Y"), wxT("Y") ) ); 
	posZ = propGrid->Append( new wxFloatProperty( wxT("Z"), wxT("Z") ) ); 
	propCategoryRot = propGrid->Append( new wxPropertyCategory( wxT("Rotation"), wxT("Rotation") ) ); 
	roll = propGrid->Append( new wxFloatProperty( wxT("Roll"), wxT("Roll") ) ); 
	yaw = propGrid->Append( new wxFloatProperty( wxT("Yaw"), wxT("Yaw") ) ); 
	pitch = propGrid->Append( new wxFloatProperty( wxT("Pitch"), wxT("Pitch") ) ); 
	propCategoryScale = propGrid->Append( new wxPropertyCategory( wxT("Scale"), wxT("Scale") ) ); 
	scaleX = propGrid->Append( new wxFloatProperty( wxT("ScaleX"), wxT("ScaleX") ) ); 
	scaleY = propGrid->Append( new wxFloatProperty( wxT("ScaleY"), wxT("ScaleY") ) ); 
	scaleZ = propGrid->Append( new wxFloatProperty( wxT("ScaleZ"), wxT("ScaleZ") ) ); 
	mainSizer->Add( propGrid, 1, wxEXPAND, 1 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
}

WX_TransformSection::~WX_TransformSection()
{
}
