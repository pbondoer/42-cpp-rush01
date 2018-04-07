#include <iostream>
#include "NcursesDisplay.hpp"
#include "WxmacDisplay.hpp"
#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"

int		main(int ac, char **av) {
	if (ac > 1) {
		std::string  param1 = std::string(av[1]);

		if (param1 == std::string("graphical")) {
			// handle graphical mode
		}
		else {
			std::cout << "Invalid command: " << param1 << std::endl;
			std::cout << "Usage: ft_GKrellM graphical OR terminal (use terminal mode by default)" << param1 << std::endl;
			return 1;
		}
	}
	else {
		// handle ncurses mode
		std::list<IMonitorModule *> lst;

		lst.push_back(new HostnameModule());

		for (std::list<IMonitorModule *>::iterator it = lst.begin();
				it != lst.end();
				it++)
		{
			IMonitorModule *m = *it;

			if (m->getType() == STRING)
			{
				std::cout << *reinterpret_cast<std::string *>(m->getData()) << std::endl;
			}
		}
	}

	return 0;
}
