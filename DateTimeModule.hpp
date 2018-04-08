/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 19:20:40 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

# include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule
{
	public:
		DateTimeModule(void);
		DateTimeModule(DateTimeModule const &obj);
		~DateTimeModule(void);

		DateTimeModule const &operator=(DateTimeModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
		std::string	getName(void);

	private:
		std::string	_data;
		void		_update(void);
};

#endif // DATETIMEMODULE_HPP
