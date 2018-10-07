#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include "IMonitorModule.hpp"

class	IMonitorDisplay {

public:
	virtual ~IMonitorDisplay( void ) = 0;

	virtual void addModule(IMonitorModule *m) = 0;
};

#endif
