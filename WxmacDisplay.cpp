#include <iostream>
#include "WxmacDisplay.hpp"

WxmacDisplay::WxmacDisplay (void) {
	std::cout << "Default constructor called" << std::endl;
	this->_display = false;
	return ;
}

WxmacDisplay::WxmacDisplay ( WxmacDisplay const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

WxmacDisplay::~WxmacDisplay( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

WxmacDisplay &		WxmacDisplay::operator=( WxmacDisplay const  & rhs ) {
	std::cout << "Assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->_modules = rhs._modules;
		this->_config = rhs._config;
		this->_display = rhs._display;
	}
	return *this;
}

void						WxmacDisplay::pushModules( IMonitorModule * module ) {
	this->_modules.push_back(module);
}

void *						WxmacDisplay::getDataModule( size_t index ) const {
	std::cout << "-----------------" << std::endl;
	std::cout << this->_modules[index] << "  " << STRING << std::endl;
//	return this->_modules[index]->getData();
	return NULL;
}

std::vector<IMonitorModule*>	WxmacDisplay::getModules( void ) const {
	return this->_modules;
}

int8_t		WxmacDisplay::getConfig( void ) const {
	return this->_config;
}

void		WxmacDisplay::setConfig( int8_t config ) {
	this->_config = config;
}

bool		WxmacDisplay::getDisplay( void ) const {
	return this->_display;
}

void		WxmacDisplay::setDisplay( bool display ) {
	this->_display = display;
}
