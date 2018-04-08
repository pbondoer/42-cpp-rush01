/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 18:38:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UsernameModule.hpp"

#include <unistd.h>

UsernameModule::UsernameModule(void) { this->_update(); }

UsernameModule::UsernameModule(UsernameModule const &obj)
{
	*this = obj;
}

UsernameModule::~UsernameModule(void) {}

UsernameModule const &UsernameModule::operator=(UsernameModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void UsernameModule::_update(void)
{
	char username[_POSIX_LOGIN_NAME_MAX];
	getlogin_r(username, _POSIX_LOGIN_NAME_MAX);
	this->_data = username;
}

std::string UsernameModule::getName(void)
{
	return "Username";
}

ModuleType UsernameModule::getType(void)
{
	return STRING;
}

void *UsernameModule::getData(void)
{
	return &this->_data;
}
