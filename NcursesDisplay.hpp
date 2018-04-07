#ifndef NCURSESDISPLAY_H
# define NCURSESDISPLAY_H

# include <iostream>
# include "IMonitorDisplay.hpp"

class	NcursesDisplay : public IMonitorDisplay {

public:
	NcursesDisplay( void );
	NcursesDisplay( NcursesDisplay const & src );
	~NcursesDisplay( void );

	NcursesDisplay & operator=( NcursesDisplay const & rhs);

	int		getFoo( void ) const ;
	void	setFoo( int const foo );

	void		pushModules( IMonitorModule & module ) {
		this->_modules.push_back(&module);
	}

	void		swapModules(size_t indexModule, size_t indexToSwap) {
		(void)indexModule;
		(void)indexToSwap;
		// std::list<IMonitorModule>::iterator it1 = this->_modules.begin();
		// std::list<IMonitorModule>::iterator it2 = this->_modules.begin();
		//
		// it1 = this->_modules.begin() + (indexModule - 1);
		//
		// IMonitorModule		*tmp = it1;
		// it1 = it2;
		// it2 = *tmp;
	}

	int8_t		getConfig( void ) const;
	void		setConfig( int8_t config );

	bool		getDisplay( void ) const;
	void		setDisplay( bool display );

private:
	int		_foo;

};


#endif
