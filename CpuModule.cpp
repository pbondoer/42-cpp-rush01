/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 22:50:00 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

#include <unistd.h>
#include <stdlib.h>
#include <iomanip>

CpuModule::CpuModule(void) { this->_update(); }

CpuModule::CpuModule(CpuModule const &obj)
{
	*this = obj;
}

CpuModule::~CpuModule(void) {}

CpuModule const &CpuModule::operator=(CpuModule const &rhs)
{
	if (this == &rhs)
		return *this;

	return *this;
}

void CpuModule::_update(void)
{
	char cpu[128];
	size_t size = sizeof(cpu);
	if (sysctlbyname("machdep.cpu.brand_string", &cpu, &size, NULL, 0) < 0) {
		this->_data = "error";
		return ;
	}

	int core_count;
	int thread_count;
	if (sysctlbyname("machdep.cpu.core_count", &core_count, &size, NULL, 0) < 0)
		core_count = 0;
	if (sysctlbyname("machdep.cpu.thread_count", &thread_count, &size, NULL, 0) < 0)
		thread_count = 0;

	std::stringstream ss;

	ss << cpu;
	ss << " (" << core_count << "C/" << thread_count << "T)";

	double load[3];
	if (getloadavg(load, 3) != -1)
		ss << " - Load: " << std::setprecision(2) << std::fixed
			<< load[0] << ", " << load[1] << ", " << load[2];

	this->_data = ss.str();
}

std::string CpuModule::getName(void)
{
	return "Processor";
}

ModuleType CpuModule::getType(void)
{
	return STRING;
}

void *CpuModule::getData(void)
{
	return &this->_data;
}
