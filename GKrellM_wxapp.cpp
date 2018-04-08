#include <iostream>
#include "GKrellM_wxapp.hpp"
#include "Frame_wxapp.hpp"

bool GKrellM_wxapp::OnInit()
{
    Frame_wxapp *frame = new Frame_wxapp( "ft_GKrellM", wxPoint(50, 50), wxSize(1024, 720) );
    frame->Show( true );
    return true;
}
