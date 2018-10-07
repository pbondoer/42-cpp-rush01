/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 20:36:41 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"
#include "bytes.hpp"

#include <cstdio>
#include <sstream>
#include <pthread.h>

NetworkModule::NetworkModule(void) { this->_update(); }

NetworkModule::NetworkModule(NetworkModule const &obj)
{
	*this = obj;
}

NetworkModule::~NetworkModule(void) {}

NetworkModule const &NetworkModule::operator=(NetworkModule const &rhs)
{
	if (this == &rhs)
		return *this;

	this->_data = rhs._data;

	return *this;
}

void *network(void *s)
{
	FILE *f = popen("netstat -w1", "r");

	if (!f)
		return s;

	char buf[4096];

	long input = 0;
	long output = 0;

	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line(buf);

		if (line.compare(0, 17, "            input") == 0 ||
				line.compare(0, 10, "   packets") == 0)
			continue;

		long a;
		std::stringstream ss(line);

		ss >> a; // packets
		ss >> a; // errs
		ss >> input; // bytes
		ss >> a; // packets
		ss >> a; // errs
		ss >> output; // bytes

		std::stringstream ss2;

		ss2 << bytes_format(input);
		ss2 << "/s in, ";
		ss2 << bytes_format(output);
		ss2 << "/s out";

		*reinterpret_cast<std::string *>(s) = ss2.str();
	}

	return s;
}

std::string NetworkModule::getName(void)
{
	return "Network";
}

void NetworkModule::_update(void)
{
	pthread_t id;

	pthread_create(&id, NULL, &network, &this->_data);
	pthread_detach(id);
}

ModuleType NetworkModule::getType(void)
{
	return STRING;
}

void *NetworkModule::getData(void)
{
	return &this->_data;
}
