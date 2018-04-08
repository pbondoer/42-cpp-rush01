#ifndef WXMACDISPLAY_H
# define WXMACDISPLAY_H

# include <iostream>
# include "IMonitorDisplay.hpp"
# include <vector>
# include <wx/wx.h>

class	WxmacDisplay : public IMonitorDisplay {

public:
	WxmacDisplay( void );
	WxmacDisplay( WxmacDisplay const & src );
	~WxmacDisplay( void );

	WxmacDisplay & operator=( WxmacDisplay const & rhs);

	void		pushModules( IMonitorModule * module );

	void		swapModules(size_t indexModule, size_t indexToSwap) {
		(void)indexModule;
		(void)indexToSwap;
	}

	std::vector<IMonitorModule*>	getModules( void ) const;
	IMonitorModule*				getModules( size_t index ) const;

	void *						getDataModule( size_t index ) const;


	int8_t		getConfig( void ) const;
	void		setConfig( int8_t config );

	bool		getDisplay( void ) const;
	void		setDisplay( bool display );

private:
	std::vector<IMonitorModule*>	_modules;
	int8_t						_config;
	bool						_display;

};


#endif
