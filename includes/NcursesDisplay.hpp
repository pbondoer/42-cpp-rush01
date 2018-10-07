#ifndef NCURSESDISPLAY_H
# define NCURSESDISPLAY_H

# include <ncurses.h>
# include <iostream>
# include <map>

# include "IMonitorDisplay.hpp"

struct Window {
	WINDOW *ptr;
	int x;
	int y;
	int width;
	int height;
};

class	NcursesDisplay : public IMonitorDisplay {

public:
	NcursesDisplay( void );
	NcursesDisplay( NcursesDisplay const & src );
	~NcursesDisplay( void );

	NcursesDisplay & operator=( NcursesDisplay const & rhs);

	void addModule(IMonitorModule *module);
	void updateAll(void);
private:
	void updateWindow(IMonitorModule *module);

	std::map<IMonitorModule *, Window> _windows;
	int _y;
	int _x;
};

#endif
