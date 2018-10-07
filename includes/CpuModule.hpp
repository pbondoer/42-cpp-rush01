/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 19:20:56 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "IMonitorModule.hpp"

class CpuModule : public IMonitorModule
{
	public:
		CpuModule(void);
		CpuModule(CpuModule const &obj);
		~CpuModule(void);

		CpuModule const &operator=(CpuModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
		std::string	getName(void);

	private:
		std::string	_data;
		void		_update(void);
};

#endif // CPUMODULE_HPP
