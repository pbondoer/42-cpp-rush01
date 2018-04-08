/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:30:38 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/08 18:36:39 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORDISPLAY_H
# define MONITORDISPLAY_H

# include <list>

# include "IMonitorDisplay.hpp"

class MonitorDisplay : public IMonitorDisplay {
	public:
		MonitorDisplay(void);
		MonitorDisplay(std::list<IMonitorModule *> lst);
		MonitorDisplay(MonitorDisplay const &obj);
		~MonitorDisplay(void);

		MonitorDisplay const &operator=(MonitorDisplay const &rhs);

		void		addModule(IMonitorModule *m);
	private:
		std::list<IMonitorModule *> _modules;
};

#endif // MONITORDISPLAY_H
