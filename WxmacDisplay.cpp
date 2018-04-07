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

int				WxmacDisplay::getFoo( void ) const {
	return this->_foo;
}

void			WxmacDisplay::setFoo( int foo ) {
	this->_foo = foo;
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
