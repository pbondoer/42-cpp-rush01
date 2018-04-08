#include <wx/wx.h>
#include "WxmacDisplay.hpp"
#include "IMonitorModule.hpp"

class TextPanel : public wxPanel
{
public:
	TextPanel(wxPanel *parent, WxmacDisplay *wxmac, IMonitorModule *m);
	TextPanel(TextPanel const &rhs);
	~TextPanel(void);

	TextPanel const &operator=(TextPanel const &obj);

	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

private:
	IMonitorModule* _module;
	wxStaticText 	*_m_title;
	wxStaticText 	*_m_content;
};
