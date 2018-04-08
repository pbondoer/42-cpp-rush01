#include "Frame_wxapp.hpp"
#include "WxmacDisplay.hpp"

Frame_wxapp::Frame_wxapp(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size), _m_timer(this, TIMER_ID)
{

	HostnameModule *s = new HostnameModule();
	std::cout << " => " << s->getType() << std::endl;

	_wxmac = new WxmacDisplay();

	_wxmac->addModule(new HostnameModule());
	_wxmac->addModule(new UsernameModule());
	_wxmac->addModule(new OsNameModule());
	_wxmac->addModule(new DateTimeModule());
	_wxmac->addModule(new RamModule());
	_wxmac->addModule(new CpuModule());
	_wxmac->addModule(new NetworkModule());

	(void)size;
	(void)pos;

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Help\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );

	// WIDGET
	_m_parent = new wxPanel(this, wxID_ANY);
	// m_bottom = new wxPanel(this, wxID_ANY);

	// panels
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

	// int widthWin;
	// int heightWin;
    //
	// wxWindow::GetSize (&widthWin, &heightWin);
    //
	// wxButton *button = new wxButton(_m_parent, wxID_EXIT, wxT("Quit"), wxPoint(widthWin - 100, heightWin - 80));
	// Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
	// wxCommandEventHandler(Frame_wxapp::OnExit));
	// button->SetFocus();

	Centre();
	_m_timer.Start(1000);

}

void Frame_wxapp::OnExit(wxCommandEvent& event)
{
	(void)event;
    Close( true );
}

void Frame_wxapp::OnAbout(wxCommandEvent& event)
{
	(void)event;
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void Frame_wxapp::OnHello(wxCommandEvent& event)
{
	(void)event;
    wxLogMessage("Roll your head on the keyboard!");
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
    EVT_MENU(ID_Hello,   Frame_wxapp::OnHello)
    EVT_MENU(wxID_EXIT,  Frame_wxapp::OnExit)
    EVT_MENU(wxID_ABOUT, Frame_wxapp::OnAbout)
	EVT_TIMER(TIMER_ID, Frame_wxapp::OnTimer)
wxEND_EVENT_TABLE()
