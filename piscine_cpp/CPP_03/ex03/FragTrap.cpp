/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:22:42 by agachet           #+#    #+#             */
/*   Updated: 2021/09/29 18:31:01 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Creation de FragTrap" << std::endl;
	return ;
}

FragTrap::FragTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Creation ""Default"" de FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &assignation)
{
	if (this != &assignation)
		this->_name = assignation._name;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destruction de FragTrap" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << this->_name <<  " Would like to do high five." << std::endl;
	return ;
}
