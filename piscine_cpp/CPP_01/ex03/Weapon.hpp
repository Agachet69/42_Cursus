/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:32:35 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 21:01:25 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(std::string Weapon);
		Weapon(void);
		~Weapon(void);
		std::string const getType() const;
		void	setType(std::string Weapon);

	private:
		std::string _Weapon;
};
#endif
