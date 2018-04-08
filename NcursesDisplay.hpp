#ifndef NCURSESDISPLAY_H
# define NCURSESDISPLAY_H

# include <ncurses.h>
# include <iostream>
# include <map>

# include "MonitorDisplay.hpp"

struct Window {
	WINDOW *ptr;
	int x;
	int y;
	int width;
	int height;
};

class	NcursesDisplay : public MonitorDisplay {

public:
	NcursesDisplay( void );
	NcursesDisplay( NcursesDisplay const & src );
	~NcursesDisplay( void );

	NcursesDisplay & operator=( NcursesDisplay const & rhs);

	void addWindow(IMonitorModule *module);
	void updateWindow(IMonitorModule *module);
private:
	std::map<IMonitorModule *, Window> _windows;
	int _y;
	int _x;
};

#endif
