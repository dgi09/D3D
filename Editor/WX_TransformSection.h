///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_TRANSFORMSECTION_H__
#define __WX_TRANSFORMSECTION_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WX_TransformSection
///////////////////////////////////////////////////////////////////////////////
class WX_TransformSection : public wxPanel 
{
	private:
	
	protected:
		wxPGProperty* propCategoryRot;
		wxPGProperty* propCategoryScale;
	
	public:
		wxPropertyGrid* propGrid;
		wxPGProperty* propCategoryPos;
		wxPGProperty* posX;
		wxPGProperty* posY;
		wxPGProperty* posZ;
		wxPGProperty* roll;
		wxPGProperty* yaw;
		wxPGProperty* pitch;
		wxPGProperty* scaleX;
		wxPGProperty* scaleY;
		wxPGProperty* scaleZ;
		
		WX_TransformSection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 153,256 ), long style = wxTAB_TRAVERSAL ); 
		~WX_TransformSection();
	
};

#endif //__WX_TRANSFORMSECTION_H__
