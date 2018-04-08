/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 19:20:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule
{
	public:
		HostnameModule(void);
		HostnameModule(HostnameModule const &obj);
		~HostnameModule(void);

		HostnameModule const &operator=(HostnameModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
		std::string	getName(void);

	private:
		std::string	_data;
		void		_update(void);
};

#endif // HOSTNAMEMODULE_HPP
