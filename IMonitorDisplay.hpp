#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>
# include <list>
# include "IMonitorModule.hpp"

class	IMonitorDisplay {

public:
	virtual ~IMonitorDisplay( void ) = 0;

	// std::list<IMonitorModule>		getModules( void ) const {
	// 	return this->_modules;
	// }

protected:
	std::list<IMonitorModule*>	_modules;
	int8_t						_config;
	bool						_display;

};

#endif
