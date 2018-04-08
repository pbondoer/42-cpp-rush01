#include <iostream>
#include "GKrellM_wxapp.hpp"
#include "Frame_wxapp.hpp"

GKrellM_wxapp::GKrellM_wxapp(void) {}
GKrellM_wxapp::GKrellM_wxapp(GKrellM_wxapp const &rhs) { *this = rhs; }
GKrellM_wxapp::~GKrellM_wxapp(void) {}

GKrellM_wxapp const &GKrellM_wxapp::operator=(GKrellM_wxapp const &)
{
	return *this;
}

bool GKrellM_wxapp::OnInit()
{
	Frame_wxapp *frame = new Frame_wxapp( "ft_GKrellM" );
	frame->Show( true );
	return true;
}
