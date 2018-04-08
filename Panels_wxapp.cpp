#include <wx/stattext.h>
#include "IMonitorModule.hpp"
#include "Frame_wxapp.hpp"

TextPanel::TextPanel(wxPanel * parent, WxmacDisplay *wxmac, IMonitorModule *module)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN),
	_module(module)
{
	this->_m_title = new wxStaticText(this, -1, wxString::Format(wxT("%s"),
				module->getName().c_str()), wxPoint(10, 5));

	wxFont font = _m_title->GetFont();
	font.SetWeight(wxFONTWEIGHT_BOLD);
	_m_title->SetFont(font);

	this->_m_content = new wxStaticText(this, -1, wxString::Format("..."),
			wxPoint(10, 30));

	(void)wxmac;
}

void	TextPanel::update(wxPanel * parent, WxmacDisplay *wxmac) const {
	(void)parent;
	(void)wxmac;

	std::string *data = reinterpret_cast<std::string *>(_module->getData());

	this->_m_content->SetLabel(wxString::Format(wxT("%s"), data->c_str()));
}
