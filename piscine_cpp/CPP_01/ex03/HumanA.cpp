/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:33:37 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 21:10:06 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon_name) : _Weapon(Weapon_name)
{
	setName(name);
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_Weapon.getType() << std::endl;
	return ;
}
