///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_DIRECTLIGHTSECTION_H__
#define __WX_DIRECTLIGHTSECTION_H__

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
/// Class WX_DirectLightSection
///////////////////////////////////////////////////////////////////////////////
class WX_DirectLightSection : public wxPanel 
{
	private:
	
	protected:
		wxPGProperty* pointTo;
		wxPGProperty* propCatLight;
	
	public:
		wxPropertyGrid* propGrid;
		wxPGProperty* propCategoryPosition;
		wxPGProperty* posX;
		wxPGProperty* posY;
		wxPGProperty* posZ;
		wxPGProperty* pointToX;
		wxPGProperty* pointToY;
		wxPGProperty* pointToZ;
		wxPGProperty* diffuse;
		
		WX_DirectLightSection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 153,216 ), long style = wxTAB_TRAVERSAL ); 
		~WX_DirectLightSection();
	
};

#endif //__WX_DIRECTLIGHTSECTION_H__
