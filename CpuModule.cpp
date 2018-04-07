/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 19:55:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

#include <unistd.h>

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
	this->_data = cpu;
}

ModuleType CpuModule::getType(void)
{
	return STRING;
}

void *CpuModule::getData(void)
{
	return &this->_data;
}
