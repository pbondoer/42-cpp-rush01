/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RotatingArray.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:19:06 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/07 21:19:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATINGARRAY_HPP
# define ROTATINGARRAY_HPP

# include <vector>

template<typename T>
class RotatingArray
{
	public:
		RotatingArray(void) : _size(0) {}
		RotatingArray(size_t size) : _size(size)
		{
			this->_arr.reserve(_size);
		}
		RotatingArray(RotatingArray const &obj)
		{
			*this = obj;
		}

		RotatingArray const &operator=(RotatingArray const &obj)
		{
			if (this == &obj)
				return *this;

			this->_size = obj._size;
			this->_arr = obj._arr;

			return *this;
		}
	private:
		std::vector<T>	_arr;
		size_t			_size;
};

#endif // ROTATINGARRAY_HPP
