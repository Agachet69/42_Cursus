/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:25:32 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 19:22:19 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	std::vector<int> store(n);
	this->_store = store;
}

Span::~Span()
{
	return ;
}

void	Span::addNumber(int number)
{
	int i;
	for (i = 0; (i < _n) && this->_store[i] != 0; i++)
		;
	if (this->_store.size() <= this->_n)
		this->_store[i] = number;
	else
		throw std::length_error("We can't add a new number there are already all of them stored.");
		//std::cout << "renvoyer une exception" << std::endl;
}

int	Span::longestSpan()
{
	int ret;

	if (this->_store.size() < 2)
		throw std::length_error("not enough numbers.");
	std::vector<int>::iterator it;
	it = this->_store.begin();
	ret = *it;
	for (it = this->_store.begin(); it != this->_store.end(); ++it)
		if (ret < (*it))
			ret = *it;
	return ret;

}

int	Span::shortestSpan()
{
	int ret;

	if (this->_store.size() < 2)
		throw std::length_error("not enough numbers.");
	std::vector<int>::iterator it;
	it = this->_store.begin();
	ret = *it;
	for (it = this->_store.begin(); it != this->_store.end(); ++it)
		if (ret > (*it))
			ret = *it;
	return ret;
}
