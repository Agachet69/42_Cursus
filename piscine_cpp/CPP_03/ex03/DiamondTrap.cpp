/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:18:57 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 18:08:34 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "Construction de DiamondTrap" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name += "_clap_name";
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << "Construction Default de Diamond" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->_name = assignation._name;
		this->_hitpoints = assignation._hitpoints;
		this->_energy_points = assignation._energy_points;
		this->_attack_damage = assignation._attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destruction de DiamondTrap" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "The name of DiamondTrap is " << this->_name << std::endl;
	std::cout << "The name of ClapTrap is " << ClapTrap::_name << std::endl;
	return ;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
	return ;
}
