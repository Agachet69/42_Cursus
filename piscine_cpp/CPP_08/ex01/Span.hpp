/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:16:54 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 17:31:48 by agachet          ###   ########.fr       */
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
		unsigned int _n;
		std::vector<int> _store;

	public:
		Span(unsigned int n);
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
};

#endif
