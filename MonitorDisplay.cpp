/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:55:08 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 17:02:52 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay(void) {}
MonitorDisplay::~MonitorDisplay(void) {}

MonitorDisplay::MonitorDisplay(std::list<IMonitorModule *> lst)
	: _modules(lst) {}

MonitorDisplay::MonitorDisplay(MonitorDisplay const &obj)
{
	*this = obj;
}


MonitorDisplay const &MonitorDisplay::operator=(MonitorDisplay const &rhs)
{
	if (this == &rhs)
		return *this;

	this->_modules = rhs._modules;

	return *this;
}

void MonitorDisplay::addModule(IMonitorModule *m)
{
	if (m == NULL || m->getType() == NONE)
		return;

	this->_modules.push_back(m);
}
