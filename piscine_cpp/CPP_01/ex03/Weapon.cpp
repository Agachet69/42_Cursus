/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:13:44 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 21:02:28 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Weapon)
{
	setType(Weapon);
	return ;
}

Weapon::Weapon()
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const Weapon::getType()const
{
	return (this->_Weapon);
}

void	Weapon::setType(std::string Weapon)
{
	this->_Weapon = Weapon;
}
