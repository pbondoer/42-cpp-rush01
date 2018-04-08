#include <wx/wx.h>
#include "WxmacDisplay.hpp"
#include "IMonitorModule.hpp"

class TextPanel : public wxPanel
{
public:
    TextPanel(wxPanel *parent, WxmacDisplay *wxmac, IMonitorModule *m);
	// virtual ~TextPanel();
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

private:
	IMonitorModule* _module;
	wxStaticText 	*_m_title;
	wxStaticText 	*_m_content;
};
