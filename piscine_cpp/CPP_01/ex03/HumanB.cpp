/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:33:35 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 21:32:52 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::setWeapon(Weapon &type)
{
	this->_Weapon = &type;
}

void	HumanB::attack()
{
	if (this->_Weapon == NULL)
		std::cout << this->_name << " has no weapon " << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_Weapon->getType() << std::endl;
}
