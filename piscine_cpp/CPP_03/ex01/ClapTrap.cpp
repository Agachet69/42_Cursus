/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:19:45 by agachet           #+#    #+#             */
/*   Updated: 2021/09/27 19:19:50 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitpoints = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "Création du ClapTrap" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->_name = assignation._name;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Fin du ClapTrap" << std::endl;
	return ;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->_attack_damage  << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_energy_points -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage(s)";
	if (this->_energy_points > 0)
		std::cout << ", there are " << this->_energy_points << " energy point(s) left." << std::endl;
	else
		std::cout << " there are no more energy point." << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_energy_points += amount;
	std::cout << "ClapTrap " << this->_name << " regain " << amount << " points";
	std::cout << " there are " << this->_energy_points << " energy point(s) left." << std::endl;
	return ;
}
