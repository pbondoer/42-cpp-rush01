#include "Frame_wxapp.hpp"
#include "WxmacDisplay.hpp"

Frame_wxapp::Frame_wxapp(Frame_wxapp const &rhs) { *this = rhs; }
Frame_wxapp::~Frame_wxapp(void) {}

Frame_wxapp const &Frame_wxapp::operator=(Frame_wxapp const &rhs)
{
	if (this == &rhs)
		return *this;

	this->_m_parent = rhs._m_parent;
	this->_wxmac = rhs._wxmac;
	this->_panels = rhs._panels;

	return *this;
}

Frame_wxapp::Frame_wxapp(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxPoint(20, 20), wxSize(1024, 720)),
	_m_timer(this, TIMER_ID)
{
	_wxmac = new WxmacDisplay();

	_wxmac->addModule(new HostnameModule());
	_wxmac->addModule(new UsernameModule());
	_wxmac->addModule(new OsNameModule());
	_wxmac->addModule(new DateTimeModule());
	_wxmac->addModule(new RamModule());
	_wxmac->addModule(new CpuModule());
	_wxmac->addModule(new NetworkModule());

	// WIDGET
	_m_parent = new wxPanel(this, wxID_ANY);

	wxBoxSizer *hbox = new wxBoxSizer(wxVERTICAL);

	const std::vector<IMonitorModule *> *lst = _wxmac->getModules();

	for (std::vector<IMonitorModule *>::const_iterator it = lst->begin();
			it != lst->end();
			it++)
	{
		TextPanel *panel = new TextPanel(_m_parent, _wxmac, *it);
		hbox->Add(panel, 1, wxEXPAND | wxALL, 5);
		_panels.push_back(panel);
	}

	_m_parent->SetSizer(hbox);

	Centre();
	_m_timer.Start(1000);

}

void Frame_wxapp::OnTimer(wxTimerEvent& event)
{
	for (std::list<TextPanel *>::iterator it = _panels.begin();
			it != _panels.end();
			it++)
	{
		(*it)->update(_m_parent, _wxmac);
	}

	(void)event;
}

wxBEGIN_EVENT_TABLE(Frame_wxapp, wxFrame)
	EVT_TIMER(TIMER_ID, Frame_wxapp::OnTimer)
wxEND_EVENT_TABLE()
