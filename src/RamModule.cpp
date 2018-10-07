/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 20:34:04 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
#include "bytes.hpp"

#include <unistd.h>
#include <sstream>
#include <iomanip>

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

	int64_t total;
	size_t size = sizeof(total);
	if (sysctlbyname("hw.memsize", &total, &size, NULL, 0) < 0) {
		this->_data = "error";
		return ;
	}

	char buf[4096];

	long bytes = 0;
	long used = 0;

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

			if (line.compare(0, 12, "Pages active") == 0 ||
					line.compare(0, 14, "Pages inactive") == 0)
				used += a;
		}

		if (line.compare(0, 20, "\"Translation faults\"") == 0)
			break;
	}

	used *= bytes;

	std::stringstream ss;

 	ss << bytes_format(used) << " / " << bytes_format(total) << " ("
 		<< std::setprecision(0) << std::fixed << (used / (double)total * 100)
 		<< "%)";

	pclose(f);

	this->_data = ss.str();
}

std::string RamModule::getName(void)
{
	return "Memory";
}

ModuleType RamModule::getType(void)
{
	return STRING;
}

void *RamModule::getData(void)
{
	this->_update();

	return &this->_data;
}
