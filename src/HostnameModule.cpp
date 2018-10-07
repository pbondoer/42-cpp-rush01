/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 18:38:39 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

#include <unistd.h>

HostnameModule::HostnameModule(void) { this->_update(); }

HostnameModule::HostnameModule(HostnameModule const &obj)
{
	*this = obj;
}

HostnameModule::~HostnameModule(void) {}

HostnameModule const &HostnameModule::operator=(HostnameModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void HostnameModule::_update(void)
{
	char hostname[_POSIX_HOST_NAME_MAX];
	gethostname(hostname, _POSIX_HOST_NAME_MAX);
	this->_data = hostname;
}

std::string HostnameModule::getName(void)
{
	return "Hostname";
}

ModuleType HostnameModule::getType(void)
{
	return STRING;
}

void *HostnameModule::getData(void)
{
	return &this->_data;
}
