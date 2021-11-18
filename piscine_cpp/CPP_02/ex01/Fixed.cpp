/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:22:27 by agachet           #+#    #+#             */
/*   Updated: 2021/10/28 15:09:24 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _PointFixe(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int nb): _PointFixe(nb << this->_NbBits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float nb): _PointFixe(roundf(nb * (1 << this->_NbBits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Detructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = (copy);
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
	return (this->_PointFixe);
}

void	Fixed::setRawBits(int const raw)
{
	this->_PointFixe = raw;
}

int	Fixed::toInt() const
{
	return (this->_PointFixe >> this->_NbBits);
}

float	Fixed::toFloat() const
{
	return ((float) this->getRawBits() / (float)(1 << this->_NbBits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &instance)
{
	out << instance.toFloat();
	return (out);
}
