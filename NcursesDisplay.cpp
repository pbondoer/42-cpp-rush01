/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:10:56 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 21:53:25 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>

#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(void)
{
	initscr(); // initialize ncurses
	start_color(); // allow colors
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	// main window flags
	keypad(stdscr, TRUE); // allow special keys
	//nodelay(stdscr, TRUE); // dont block the main thread when querying keys
	//scrollok(stdscr, FALSE); // dont allow scrolling the window

	// get dimensions
	getmaxyx(stdscr, this->_y, this->_x);

	// init colors
	init_color(COLOR_CYAN, 500, 500, 500);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	refresh();
}

NcursesDisplay::~NcursesDisplay(void)
{
	// foreach win
	// delwin(win)

	endwin();
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const &src)
{
	*this = src;
}

NcursesDisplay	&NcursesDisplay::operator=( NcursesDisplay const  & rhs ) {
	if (this == &rhs)
		return *this;

	return *this;
}

void NcursesDisplay::updateWindow(IMonitorModule *module)
{
	if (!this->_windows.count(module))
		return;

	Window win = this->_windows[module];

	werase(win.ptr);

	// title bar
	wattron(win.ptr, COLOR_PAIR(1));
	wmove(win.ptr, 0, 0);
	whline(win.ptr, ACS_HLINE, COLS);
	wmove(win.ptr, 0, 1);
	waddstr(win.ptr, " ");
	waddstr(win.ptr, module->getName().c_str());
	waddstr(win.ptr, " ");
	wattroff(win.ptr, COLOR_PAIR(1));

	// content
	if (module->getType() == STRING)
	{
		std::string *s = reinterpret_cast<std::string *>(module->getData());

		wmove(win.ptr, 1, 0);
		if (s->length() == 0)
			waddstr(win.ptr, "...");
		else
			waddstr(win.ptr, s->c_str());
	}

	// display the window
	wrefresh(win.ptr);
}

void NcursesDisplay::updateAll(void)
{
	for (std::map<IMonitorModule *, Window>::iterator it = this->_windows.begin();
			it != this->_windows.end();
			it++)
	{
		this->updateWindow(it->first);
	}
}

void NcursesDisplay::addModule(IMonitorModule *module)
{
	static Window last;

	int y = 0;
	if (!this->_windows.empty())
	{
		y = last.y + last.height;
	}

	Window win;

	win.x = 0;
	win.y = y;
	win.width = COLS;
	win.height = 3;
	win.ptr = newwin(win.height, win.width, win.y, win.x);

	this->_windows[module] = win;
	last = win;

	updateWindow(module);
}
