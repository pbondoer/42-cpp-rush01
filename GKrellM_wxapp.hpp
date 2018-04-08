#ifndef GKRELLM_WXAPP_H
# define GKRELLM_WXAPP_H

# include <wx/wx.h>

class GKrellM_wxapp : public wxApp
{

public:
    virtual bool OnInit();

};

DECLARE_APP(GKrellM_wxapp);

#endif
