///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_POINTLIGHTSECTION_H__
#define __WX_POINTLIGHTSECTION_H__

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
/// Class WX_PointLightSection
///////////////////////////////////////////////////////////////////////////////
class WX_PointLightSection : public wxPanel 
{
	private:
	
	protected:
		wxPGProperty* propCategoryLight;
	
	public:
		wxPropertyGrid* propGrid;
		wxPGProperty* propCategoryPos;
		wxPGProperty* posX;
		wxPGProperty* posY;
		wxPGProperty* posZ;
		wxPGProperty* Diffuse;
		wxPGProperty* Range;
		
		WX_PointLightSection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 153,158 ), long style = wxTAB_TRAVERSAL ); 
		~WX_PointLightSection();
	
};

#endif //__WX_POINTLIGHTSECTION_H__
