/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:22:42 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 20:13:14 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "Creation de FragTrap par Default" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "Creation de FragTrap" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &assignation)
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

FragTrap::~FragTrap()
{
	std::cout << "Destruction de FragTrap" << std::endl;
	return ;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage  << " points of damage!" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << this->_name <<  " Would like to do high five." << std::endl;
	return ;
}
