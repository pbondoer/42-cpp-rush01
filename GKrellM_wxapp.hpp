#ifndef GKRELLM_WXAPP_H
# define GKRELLM_WXAPP_H

# include <wx/wx.h>

class GKrellM_wxapp : public wxApp
{

public:
	GKrellM_wxapp(void);
	GKrellM_wxapp(GKrellM_wxapp const &rhs);
	~GKrellM_wxapp(void);

	GKrellM_wxapp const &operator=(GKrellM_wxapp const &obj);
    virtual bool OnInit();

};

DECLARE_APP(GKrellM_wxapp);

#endif
