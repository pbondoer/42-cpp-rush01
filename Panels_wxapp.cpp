#include <wx/stattext.h>
#include "Frame_wxapp.hpp"

ABasicPanel::ABasicPanel(wxPanel * parent, WxmacDisplay *wxmac, std::string m_title)
       : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	this->_m_title = new wxStaticText(this, -1, wxString::Format(wxT("%s"), m_title.c_str()), wxPoint(10, 5));
	(void)wxmac;
}

FirstPanel::FirstPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title)
		: ABasicPanel(parent, wxmac, m_title)
{



	// data = *reinterpret_cast<std::string *>(wxmac->getDataModule(0));
	// wxPuts(data.c_str());
	// this->_m_username = new wxStaticText(this, -1, wxString::Format(wxT("%s"), data.c_str()), wxPoint(10, 5));
    //
	// data = *reinterpret_cast<std::string *>(wxmac->getModules(1)->getData());
	// this->_m_hostname = new wxStaticText(this, -1, wxString::Format(wxT("%s"), data.c_str()), wxPoint(10, 5));
    //
	// data = *reinterpret_cast<std::string *>(wxmac->getModules(2)->getData());
	// this->_m_osname = new wxStaticText(this, -1, wxString::Format(wxT("%s"), data.c_str()), wxPoint(10, 5));

	this->update(parent, wxmac);
}

void	FirstPanel::update(wxPanel * parent, WxmacDisplay *wxmac) const {
	std::string		data;

	std::cout << wxmac->getDataModule(0);
	// data = *reinterpret_cast<std::string *>(wxmac->getDataModule(0));
	(void)parent;
	(void)wxmac;
}

SecondPanel::SecondPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title)
		: ABasicPanel(parent, wxmac, m_title)
{
	this->update(parent, wxmac);
}

void	SecondPanel::update(wxPanel * parent, WxmacDisplay *wxmac) const {
	(void)parent;
	(void)wxmac;
}

ThirdPanel::ThirdPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title)
		: ABasicPanel(parent, wxmac, m_title)
{
	this->update(parent, wxmac);
}

void	ThirdPanel::update(wxPanel * parent, WxmacDisplay *wxmac) const {
	(void)parent;
	(void)wxmac;
}

FourthPanel::FourthPanel(wxPanel *parent, WxmacDisplay *wxmac, std::string m_title)
		: ABasicPanel(parent, wxmac, m_title)
{
	this->update(parent, wxmac);
}

void	FourthPanel::update(wxPanel * parent, WxmacDisplay *wxmac) const {
	(void)parent;
	(void)wxmac;
}
