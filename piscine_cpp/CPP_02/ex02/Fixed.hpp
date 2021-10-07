/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:46:05 by agachet           #+#    #+#             */
/*   Updated: 2021/09/27 16:50:48 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(const int);
		Fixed(const float);
		Fixed(void);
		Fixed(const Fixed& copy);
		~Fixed(void);

		Fixed	&operator=(const Fixed&);
		Fixed	operator+(const Fixed&);
		Fixed	operator-(const Fixed&);
		Fixed	operator*(const Fixed&);
		Fixed	operator/(const Fixed&);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		int	operator>(const Fixed&);
		int	operator>=(const Fixed&);
		int	operator<(const Fixed&);
		int	operator<=(const Fixed&);
		int	operator==(const Fixed&);
		int	operator!=(const Fixed&);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	const &min(Fixed const &a, Fixed const &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	const &max(Fixed const &a, Fixed const &b);


	private:
		int _PointFixe;
		static const int _NbBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
