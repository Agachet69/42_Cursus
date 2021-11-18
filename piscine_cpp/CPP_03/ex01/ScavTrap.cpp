/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:20:02 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 17:31:14 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Creation Scavtrap par Default" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "Creation Scavtrap" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap &assignation)
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

ScavTrap::~ScavTrap()
{
	std::cout << "Destruction Scavtrap" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
	return ;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage  << " points of damage!" << std::endl;
	return ;
}
