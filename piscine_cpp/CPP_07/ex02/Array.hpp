/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:29 by agachet           #+#    #+#             */
/*   Updated: 2021/11/02 18:05:57 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *_tab;
		unsigned int _n;

	public:
		Array<T>() : _tab(NULL), _n(0)
		{
			return ;
		}

		Array<T>(unsigned int n) : _n(n)
		{
			this->_tab = new T[n];
		}

		Array<T>(Array<T> const &c)
		{
			this->_tab = new T[c.size()];
			for (int i = 0; i < c.size(); i++)
				this->_tab[i] = c._tab[i];
			this->_n = c._n;
		}

		~Array()
		{
			if (this->_n > 0)
				delete this->_tab;
		}

		Array<T>	&operator=(Array<T> const &a)
		{
			this->_n = a._n;
			if (a._n > 0)
			{
				this->_tab = new T[_n];
				for (int i = 0; i < a.size(); i++)
					this->_tab = a._tab[i];
				return (*this);
			}
			this->_tab = NULL;
			return *this;
		}

		T		&operator[](int i)
		{
			if (i >= (int)_n)
				throw Array<T>::OutOfRange();
			return this->_tab[i];
		}

		int	size() const
		{
			return this->_n;
		}

		class OutOfRange: public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Out of limits";
			}
		};
};

#endif
