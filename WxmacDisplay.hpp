#ifndef WXMACDISPLAY_H
# define WXMACDISPLAY_H

# include <iostream>
# include "IMonitorDisplay.hpp"

class	WxmacDisplay : public IMonitorDisplay {

public:
	WxmacDisplay( void );
	WxmacDisplay( WxmacDisplay const & src );
	~WxmacDisplay( void );

	WxmacDisplay & operator=( WxmacDisplay const & rhs);

	int		getFoo( void ) const ;
	void	setFoo( int const foo );

	void		pushModules( IMonitorModule & module ) {
		this->_modules.push_back(&module);
	}

	void		swapModules(size_t indexModule, size_t indexToSwap) {
		(void)indexModule;
		(void)indexToSwap;
	}

	int8_t		getConfig( void ) const;
	void		setConfig( int8_t config );

	bool		getDisplay( void ) const;
	void		setDisplay( bool display );

private:
	int		_foo;

};


#endif
