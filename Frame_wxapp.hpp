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

# include <list>

class Frame_wxapp : public wxFrame {

public:
	Frame_wxapp(const wxString& title);
	Frame_wxapp(Frame_wxapp const &rhs);
	~Frame_wxapp(void);

	Frame_wxapp const &operator=(Frame_wxapp const &rhs);

private:
	void	OnTimer(wxTimerEvent& event);

	wxTimer			_m_timer;
	wxDECLARE_EVENT_TABLE();
	WxmacDisplay	*_wxmac;

	// WIDGET
	std::list<TextPanel *> _panels;

	wxPanel *_m_parent;
};

#define TIMER_ID 1

#endif
