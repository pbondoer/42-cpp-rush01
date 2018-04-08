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
		NcursesDisplay nc;

		nc.addModule(new HostnameModule());
		nc.addModule(new UsernameModule());
		nc.addModule(new OsNameModule());
		nc.addModule(new DateTimeModule());
		nc.addModule(new RamModule());
		nc.addModule(new CpuModule());
		nc.addModule(new NetworkModule());

		while (true)
		{
			nc.updateAll();
			napms(1000);
		}
	}

	return 0;
}
