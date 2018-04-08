#include <iostream>
#include "GKrellM_wxapp.hpp"
#include "Frame_wxapp.hpp"
// #include "Panels_wxapp.hpp"

bool GKrellM_wxapp::OnInit()
{
    Frame_wxapp *frame = new Frame_wxapp( "ft_GKrellM", wxPoint(20, 20), wxSize(1024, 720) );
    frame->Show( true );
    return true;
}
