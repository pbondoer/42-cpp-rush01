#include "Frame_wxapp.hpp"
#include "WxmacDisplay.hpp"

Frame_wxapp::Frame_wxapp(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size), _m_timer(this, TIMER_ID)
{

	HostnameModule *s = new HostnameModule();
	std::cout << " => " << s->getType() << std::endl;

	_wxmac = new WxmacDisplay();

	_wxmac->pushModules(new HostnameModule());
	_wxmac->pushModules(new UsernameModule());
	_wxmac->pushModules(new OsNameModule());
	_wxmac->pushModules(new DateTimeModule());
	_wxmac->pushModules(new RamModule());
	_wxmac->pushModules(new CpuModule());
	_wxmac->pushModules(new NetworkModule());

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
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Wonderful message" );
	wxPuts(wxGetHomeDir());
	wxPuts(wxGetOsDescription());
	wxPuts(wxGetUserName());
	wxPuts(wxGetFullHostName());
	wxDateTime now = wxDateTime::Now();
	wxPrintf(wxT("Paris: %s\n"), now.Format(wxT("%a %T"),
		wxDateTime::UTC).c_str());
	long mem = wxGetFreeMemory().ToLong();
	wxPrintf(wxT("Memory: %ld\n"), mem);


	// BUTTON
	// wxPanel *panel = new wxPanel(this, wxID_ANY);


	// WIDGET
	_m_parent = new wxPanel(this, wxID_ANY);
	// m_bottom = new wxPanel(this, wxID_ANY);

	wxBoxSizer *hbox = new wxBoxSizer(wxVERTICAL);
    //
	_m_1p = new FirstPanel(_m_parent, _wxmac, "General Informations");
	_m_2p = new SecondPanel(_m_parent, _wxmac, "CPU module");
	_m_3p = new ThirdPanel(_m_parent, _wxmac, "RAM module");
	_m_4p = new FourthPanel(_m_parent, _wxmac, "Network module");
	// // m_lp = new BottomPanel(m_bottom);
    // //
	hbox->Add(_m_1p, 1, wxEXPAND | wxALL, 5);
	hbox->Add(_m_2p, 1, wxEXPAND | wxALL, 5);
	hbox->Add(_m_3p, 1, wxEXPAND | wxALL, 5);
	hbox->Add(_m_4p, 1, wxEXPAND | wxALL, 5);
	// // hbox->Add(m_lp, 1, wxEXPAND | wxALL, 5);

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
	_m_1p->update(_m_parent, _wxmac);
	_m_2p->update(_m_parent, _wxmac);
	_m_3p->update(_m_parent, _wxmac);
	_m_4p->update(_m_parent, _wxmac);
	(void)event;
}

wxBEGIN_EVENT_TABLE(Frame_wxapp, wxFrame)
    EVT_MENU(ID_Hello,   Frame_wxapp::OnHello)
    EVT_MENU(wxID_EXIT,  Frame_wxapp::OnExit)
    EVT_MENU(wxID_ABOUT, Frame_wxapp::OnAbout)
	EVT_TIMER(TIMER_ID, Frame_wxapp::OnTimer)
wxEND_EVENT_TABLE()
