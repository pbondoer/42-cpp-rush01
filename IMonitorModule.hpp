#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <iostream>

class	IMonitorModule {

public:
	virtual ~IMonitorModule( void ) = 0;

	// void *		getData( void ) const {
	// 	return this->_data;
	// }
    //
	// void		setData( void * data ) {
	// 	this->_data = data;
	// }
    //
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
	bool		_running;
	void *		_data;
};

#endif
