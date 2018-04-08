/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:31:53 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 19:52:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iomanip>

std::string bytes_format(long bytes)
{
	static const std::string s[] = {
		"bytes", "Kb", "Mb", "Gb", "Tb", "Eb"
	};

	long double b = bytes;

	int i = 0;

	for (i = 0; b >= 1024 && i < 6; i++)
		b /= 1024;

	std::stringstream ss;
	ss << std::setprecision((i == 0 ? 0 : 2)) << std::fixed << b << " " << s[i];

	return ss.str();

}
