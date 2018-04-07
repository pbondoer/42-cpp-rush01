/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 19:55:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

#include <unistd.h>

RamModule::RamModule(void) { this->_update(); }

RamModule::RamModule(RamModule const &obj)
{
	*this = obj;
}

RamModule::~RamModule(void) {}

RamModule const &RamModule::operator=(RamModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void RamModule::_update(void)
{
	FILE *f = popen("vm_stat", "r");

	if (!f) {
		this->_data = "error";
		return ;
	}

	char buf[4096];

	long total = 0;
	long bytes = 0;
	long mem_free = 0;

	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line = buf;

		if (line.compare(0, 4, "Mach") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			ss >> bytes;
		}
		if (line.compare(0, 5, "Pages") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			int a;
			ss >> a;

			total += a;

			if (line.compare(0, 10, "Pages free") == 0)
				mem_free = a;
		}

		if (line.compare(0, 20, "\"Translation faults\"") == 0)
			break;
	}

	std::stringstream ss;

 	ss << ((total - mem_free) * bytes / 1024.0f / 1024.0f / 1024.0f) << " / " <<
		 (total * bytes / 1024.0f / 1024.0f / 1024.0f) << " GB";

	pclose(f);

	this->_data = ss.str();
}

ModuleType RamModule::getType(void)
{
	return STRING;
}

void *RamModule::getData(void)
{
	return &this->_data;
}
