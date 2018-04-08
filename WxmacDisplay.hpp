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

	void		addModule( IMonitorModule * module );

	const std::vector<IMonitorModule*>	*getModules( void ) const;
	IMonitorModule*				getModules( size_t index ) const;

	void *						getDataModule( size_t index ) const;

private:
	std::vector<IMonitorModule*>	_modules;

};


#endif
