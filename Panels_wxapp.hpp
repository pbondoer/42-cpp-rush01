#include <wx/wx.h>
#include "WxmacDisplay.hpp"

class ABasicPanel : public wxPanel
{
public:
    ABasicPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	// virtual ~ABasicPanel();
	virtual void	update(wxPanel *parent, WxmacDisplay *wxmac) const = 0;

private:
	wxStaticText 	*_m_title;
};

class FirstPanel : public ABasicPanel
{
public:
    FirstPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

// private:
	// wxStaticText 	*_m_username;
	// wxStaticText 	*_m_hostname;
	// wxStaticText 	*_m_osname;
	// wxStaticText 	*_m_date_time;
};

class SecondPanel : public ABasicPanel
{
public:
    SecondPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

};

class ThirdPanel : public ABasicPanel
{
public:
    ThirdPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

};

class FourthPanel : public ABasicPanel
{
public:
    FourthPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;

};

class BottomPanel : public ABasicPanel
{
public:
    BottomPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title);
	void	update(wxPanel *parent, WxmacDisplay *wxmac) const;
};
