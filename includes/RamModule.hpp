/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 19:20:47 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "IMonitorModule.hpp"

class RamModule : public IMonitorModule
{
	public:
		RamModule(void);
		RamModule(RamModule const &obj);
		~RamModule(void);

		RamModule const &operator=(RamModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
		std::string	getName(void);

	private:
		std::string	_data;
		void		_update(void);
};

#endif // RAMMODULE_HPP
