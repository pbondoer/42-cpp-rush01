#include <iostream>
#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay (void) {
	std::cout << "Default constructor called" << std::endl;
	this->_display = false;
	return ;
}

NcursesDisplay::NcursesDisplay ( NcursesDisplay const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

NcursesDisplay::~NcursesDisplay( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int				NcursesDisplay::getFoo( void ) const {
	return this->_foo;
}

void			NcursesDisplay::setFoo( int foo ) {
	this->_foo = foo;
	return ;
}

NcursesDisplay &		NcursesDisplay::operator=( NcursesDisplay const  & rhs ) {
	std::cout << "Assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->_modules = rhs._modules;
		this->_config = rhs._config;
		this->_display = rhs._display;
	}
	return *this;
}

int8_t		NcursesDisplay::getConfig( void ) const {
	return this->_config;
}

void		NcursesDisplay::setConfig( int8_t config ) {
	this->_config = config;
}

bool		NcursesDisplay::getDisplay( void ) const {
	return this->_display;
}

void		NcursesDisplay::setDisplay( bool display ) {
	this->_display = display;
}
