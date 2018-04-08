#include <iostream>
#include "NcursesDisplay.hpp"
#include "WxmacDisplay.hpp"
#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OsNameModule.hpp"
#include "DateTimeModule.hpp"
#include "RamModule.hpp"
#include "CpuModule.hpp"
#include "NetworkModule.hpp"
#include "WxmacDisplay.hpp"
#include "GKrellM_wxapp.hpp"
#include "Frame_wxapp.hpp"

#include <unistd.h>

IMPLEMENT_APP_NO_MAIN(GKrellM_wxapp)

int		main(int argc, char **argv) {
	if (argc > 1) {
		std::string  param1 = std::string(argv[1]);

		if (param1 == std::string("graphical")) {
			// handle graphical mode

			wxEntryStart( argc, argv );
			wxTheApp->CallOnInit();
			wxTheApp->OnRun();
			wxTheApp->OnExit();
			wxEntryCleanup();
			return 0;
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
		lst.push_back(new UsernameModule());
		lst.push_back(new OsNameModule());
		lst.push_back(new DateTimeModule());
		lst.push_back(new RamModule());
		lst.push_back(new CpuModule());
		lst.push_back(new NetworkModule());

		IMonitorModule *m;
		for (std::list<IMonitorModule *>::iterator it = lst.begin();
				it != lst.end();
				it++)
		{
			m = *it;

			if (m->getType() == STRING)
			{
				std::cout << *reinterpret_cast<std::string *>(m->getData()) << std::endl;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			sleep(2);
			std::cout << *reinterpret_cast<std::string *>(m->getData()) << std::endl;
		}

	}

	return 0;
}
