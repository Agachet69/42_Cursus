/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:18:57 by agachet           #+#    #+#             */
/*   Updated: 2021/10/04 14:50:49 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name += "_clap_name"), FragTrap(name += "_clap_name"), ScavTrap(name += "_clap_name"), _name(name)
{
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "Construction de DiamondTrap" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name += "_clap_name";
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "Construction ""Default"" de Diamond" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	*this = copy;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destruction de Diamond" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "The name of DiamondTrap is " << DiamondTrap::_name << std::endl;
	std::cout << "The name of ClapTrap is " << ClapTrap::_name << std::endl;
	return ;
}
