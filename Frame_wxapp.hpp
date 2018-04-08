#ifndef FRAME_WXAPP_H
# define FRAME_WXAPP_H

# include <wx/wx.h>

class Frame_wxapp: public wxFrame {

public:
    Frame_wxapp(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();

};

enum MenuCommand
{
	ID_Hello = 1
};

#endif
