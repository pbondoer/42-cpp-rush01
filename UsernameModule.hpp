/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 19:55:58 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAMEMODULE_HPP
# define USERNAMEMODULE_HPP

# include "IMonitorModule.hpp"

class UsernameModule : public IMonitorModule
{
	public:
		UsernameModule(void);
		UsernameModule(UsernameModule const &obj);
		~UsernameModule(void);

		UsernameModule const &operator=(UsernameModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
	private:
		std::string	_data;
		void		_update(void);
};

#endif // USERNAMEMODULE_HPP
