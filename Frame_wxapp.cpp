#include "Frame_wxapp.hpp"
#include "WxmacDisplay.hpp"

Frame_wxapp::Frame_wxapp(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	WxmacDisplay *	wxmac = new WxmacDisplay();
	(void)wxmac;

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&HELP\tCtrl-H",
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

wxBEGIN_EVENT_TABLE(Frame_wxapp, wxFrame)
    EVT_MENU(ID_Hello,   Frame_wxapp::OnHello)
    EVT_MENU(wxID_EXIT,  Frame_wxapp::OnExit)
    EVT_MENU(wxID_ABOUT, Frame_wxapp::OnAbout)
wxEND_EVENT_TABLE()
