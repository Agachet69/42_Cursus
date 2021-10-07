/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:55:50 by agachet           #+#    #+#             */
/*   Updated: 2021/09/23 18:12:00 by agachet          ###   ########.fr       */
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

		Fixed &operator=(const Fixed&);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int _PointFixe;
		static const int _NbBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
