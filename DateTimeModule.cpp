/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 23:01:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"

#include <unistd.h>

DateTimeModule::DateTimeModule(void) { this->_update(); }

DateTimeModule::DateTimeModule(DateTimeModule const &obj)
{
	*this = obj;
}

DateTimeModule::~DateTimeModule(void) {}

DateTimeModule const &DateTimeModule::operator=(DateTimeModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void DateTimeModule::_update(void)
{
	char s[128];
	time_t t = time(0);
	struct tm *p = localtime(&t);

	strftime(s, 128, "%c", p);
	this->_data = s;
}

std::string DateTimeModule::getName(void)
{
	return "Date/Time";
}

ModuleType DateTimeModule::getType(void)
{
	return STRING;
}

void *DateTimeModule::getData(void)
{
	this->_update();

	return &this->_data;
}
