/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:16:54 by agachet           #+#    #+#             */
/*   Updated: 2021/11/10 17:19:17 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>

class Span
{
	private:
		unsigned int	_space;
		unsigned int _n;
		std::vector<int> *_store;

	public:
		Span();
		Span(unsigned int n);
		~Span();

		void	addNumber(int number);
		void	addRange(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite);
		int		shortestSpan();
		int		longestSpan();

		class numberExceptionEmpty: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class numberExceptionFull: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif
