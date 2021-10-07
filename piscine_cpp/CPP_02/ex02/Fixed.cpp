/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:51:18 by agachet           #+#    #+#             */
/*   Updated: 2021/09/27 16:53:41 by agachet          ###   ########.fr       */
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

Fixed Fixed::operator+(Fixed const &cmp)
{
	Fixed result = this->toFloat() + cmp.toFloat();
	return (result);
}

Fixed Fixed::operator-(Fixed const &cmp)
{
	Fixed result = this->toFloat() - cmp.toFloat();
	return (result);
}

Fixed Fixed::operator*(Fixed const &cmp)
{
	Fixed result = this->toFloat() * cmp.toFloat();
	return (result);
}

Fixed Fixed::operator/(Fixed const &cmp)
{
	Fixed result = this->toFloat() / cmp.toFloat();
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->_PointFixe += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	this->_PointFixe += 1;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_PointFixe -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp = *this;
	this->_PointFixe -= 1;
	return (tmp);
}

int		Fixed::operator>(Fixed const &cmp)
{
	if (this->_PointFixe > cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::operator>=(Fixed const &cmp)
{
	if (this->_PointFixe >= cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::operator<(Fixed const &cmp)
{
	if (this->_PointFixe < cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::operator<=(Fixed const &cmp)
{
	if (this->_PointFixe <= cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::operator==(Fixed const &cmp)
{
	if (this->_PointFixe == cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::operator!=(Fixed const &cmp)
{
	if (this->_PointFixe != cmp._PointFixe)
		return (1);
	return (0);
}

int		Fixed::getRawBits() const
{
	return (this->_PointFixe);
}

void	Fixed::setRawBits(int const raw)
{
	this->_PointFixe = raw;
}

int		Fixed::toInt() const
{
	return (this->_PointFixe >> this->_NbBits);
}

float	Fixed::toFloat() const
{
	return ((float) this->getRawBits() / (float)(1 << this->_NbBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._PointFixe < b._PointFixe)
		return (a);
	return (b);
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._PointFixe < b._PointFixe)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._PointFixe < b._PointFixe)
		return (b);
	return (a);
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._PointFixe < b._PointFixe)
		return (b);
	return (a);
}

std::ostream &operator<<(std::ostream &out, Fixed const &instance)
{
	out << instance.toFloat();
	return (out);
}
