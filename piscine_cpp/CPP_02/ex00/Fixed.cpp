/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:19:44 by agachet           #+#    #+#             */
/*   Updated: 2021/09/23 15:47:48 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _PointFixe(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = (copy);
}

Fixed::~Fixed()
{
	std::cout << "Detructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->_PointFixe = assignation.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->_PointFixe);
}

void	Fixed::setRawBits(int const raw)
{
	this->_PointFixe = raw;
}
