///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WX_MATERIALSECTION_H__
#define __WX_MATERIALSECTION_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/sizer.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WX_MaterialSection
///////////////////////////////////////////////////////////////////////////////
class WX_MaterialSection : public wxPanel 
{
	private:
	
	protected:
		wxStaticLine* m_staticline1;
		wxPGProperty* Illumination;
		wxStaticLine* m_staticline2;
	
	public:
		wxChoice* cbSubsets;
		wxPropertyGrid* propGridIllumination;
		wxPGProperty* illuminate;
		wxPropertyGrid* propGrid;
		wxPGProperty* propCategoryMat;
		wxPGProperty* useDiffuse;
		wxPGProperty* diffTexture;
		wxPGProperty* diffColor;
		wxPGProperty* useBump;
		wxPGProperty* bumpMap;
		wxPGProperty* emmisive;
		wxPGProperty* specular;
		wxPGProperty* specInt;
		
		WX_MaterialSection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 209,343 ), long style = wxTAB_TRAVERSAL ); 
		~WX_MaterialSection();
	
};

#endif //__WX_MATERIALSECTION_H__
