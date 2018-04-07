/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 19:55:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsNameModule.hpp"

#include <unistd.h>

OsNameModule::OsNameModule(void) { this->_update(); }

OsNameModule::OsNameModule(OsNameModule const &obj)
{
	*this = obj;
}

OsNameModule::~OsNameModule(void) {}

OsNameModule const &OsNameModule::operator=(OsNameModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void OsNameModule::_update(void)
{
	struct utsname uts;
	uname(&uts);
	this->_data = uts.version;
}

ModuleType OsNameModule::getType(void)
{
	return STRING;
}

void *OsNameModule::getData(void)
{
	return &this->_data;
}
