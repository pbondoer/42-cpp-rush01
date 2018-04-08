#ifndef FRAME_WXAPP_H
# define FRAME_WXAPP_H

# include <wx/wx.h>
# include "Panels_wxapp.hpp"
# include "IMonitorModule.hpp"
# include "HostnameModule.hpp"
# include "UsernameModule.hpp"
# include "OsNameModule.hpp"
# include "DateTimeModule.hpp"
# include "RamModule.hpp"
# include "CpuModule.hpp"
# include "NetworkModule.hpp"

class Frame_wxapp: public wxFrame {

public:
    Frame_wxapp(const wxString& title, const wxPoint& pos, const wxSize& size);

	void	OnTimer(wxTimerEvent& event);

private:
    void	OnHello(wxCommandEvent& event);
    void	OnExit(wxCommandEvent& event);
    void	OnAbout(wxCommandEvent& event);
	wxTimer		_m_timer;
    wxDECLARE_EVENT_TABLE();
	WxmacDisplay *_wxmac;

	// WIDGET
	FirstPanel *_m_1p;
	SecondPanel *_m_2p;
	ThirdPanel *_m_3p;
	FourthPanel *_m_4p;
	// BottomPanel *_m_lp;

	wxPanel *_m_parent;
	// wxPanel *_m_bottom;

};

enum MenuCommand
{
	ID_Hello = 1,
	TIMER_ID = 2
};

#endif
