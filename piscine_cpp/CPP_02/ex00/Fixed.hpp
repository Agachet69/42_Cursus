/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:16:39 by agachet           #+#    #+#             */
/*   Updated: 2021/09/22 14:57:31 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _PointFixe;
		static const int _NbBits = 8;
};

#endif
