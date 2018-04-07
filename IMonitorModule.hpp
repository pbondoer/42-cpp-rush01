#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <iostream>
# include <sys/utsname.h>
# include <sys/sysctl.h>
# include <unistd.h>
# include <climits>
# include <ctime>
# include <cstdio>
# include <cstdlib>
# include <sstream>

enum ModuleType {
	NONE,
	STRING,
	GRAPHIC
};

class	IMonitorModule {

public:
	virtual ~IMonitorModule( void ) = 0;

	virtual void			*getData(void) = 0;
	virtual ModuleType		getType(void) = 0;

	// bool		getRunning( void ) const {
	// 	return this->_running;
	// }
    //
	// void		setRunning( bool running ) {
	// 	this->_running = running;
	// }
    //
	// void		setRunning( void ) {
	// 	if (this->_running) {
	// 		this->_running = false;
	// 		return ;
	// 	}
	// 	this->_running = true;
	// }

protected:
	virtual void	_update(void) = 0;
};

#endif
