/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:07:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 20:32:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "IMonitorModule.hpp"
# include "RotatingArray.hpp"

class NetworkModule : public IMonitorModule
{
	public:
		NetworkModule(void);
		NetworkModule(NetworkModule const &obj);
		~NetworkModule(void);

		NetworkModule const &operator=(NetworkModule const &rhs);

		ModuleType	getType(void);
		void		*getData(void);
	private:
		RotatingArray<int> _data;
		void		_update(void);
};

#endif // NETWORKMODULE_HPP
