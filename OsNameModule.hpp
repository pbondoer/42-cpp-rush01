/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 19:55:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSNAMEMODULE_HPP
# define OSNAMEMODULE_HPP

# include "IMonitorModule.hpp"

class OsNameModule : public IMonitorModule
{
	public:
		OsNameModule(void);
		OsNameModule(OsNameModule const &obj);
		~OsNameModule(void);

		OsNameModule const &operator=(OsNameModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
	private:
		std::string	_data;
		void		_update(void);
};

#endif // OSNAMEMODULE_HPP
