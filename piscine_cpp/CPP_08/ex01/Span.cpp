/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:25:32 by agachet           #+#    #+#             */
/*   Updated: 2021/11/10 17:22:27 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->_n = 0;
	this->_space = 0;
	this->_store = new std::vector<int>[0];
	return ;
}

Span::Span(unsigned int n) : _n(n)
{
	this->_n = n;
	this->_space = 0;
	this->_store = new std::vector<int>[this->_n];
	return ;
}

Span::~Span()
{
	delete [] this->_store;
	return ;
}

void	Span::addNumber(int number)
{
	try
	{
		if (this->_space == this->_n)
			throw numberExceptionFull();
		this->_store->push_back(number);
		this->_space++;
	}
	catch(numberExceptionFull& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Span::addRange(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite)
{
	while (it < ite)
	{
		if (this->_space == this->_n)
			throw numberExceptionFull();
		this->_store->push_back(*it);
		it++;
		this->_space++;
	}
}

int	Span::longestSpan()
{
	int ret;

	if (this->_store->size() < 2)
		throw std::length_error("not enough numbers.");
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	it = this->_store->begin();
	ret = 0;
	for (it = this->_store->begin(); it != this->_store->end(); ++it)
	{
		for (it2 = it + 1; it2 != this->_store->end(); it2++)
		{
			int tmp = *it - *it2;
			if (tmp < 0)
				tmp *= -1;
			if (ret < tmp)
				ret = tmp;
		}
	}
	return ret;
}

int	Span::shortestSpan()
{
	int ret;

	if (this->_store->size() < 2)
		throw std::length_error("not enough numbers.");
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	it = this->_store->begin();
	ret = 2147483647;
	for (it = this->_store->begin(); it != this->_store->end(); ++it)
	{
		for (it2 = it + 1; it2 != this->_store->end(); it2++)
		{
			int tmp = *it - *it2;
			if (tmp < 0)
				tmp *= -1;
			if (ret > tmp)
				ret = tmp;
		}
	}
	return ret;
}

const char *Span::numberExceptionEmpty::what() const throw()
{
	return ("it's empty or just one number");
}

const char *Span::numberExceptionFull::what() const throw()
{
	return ("it's full");
}
