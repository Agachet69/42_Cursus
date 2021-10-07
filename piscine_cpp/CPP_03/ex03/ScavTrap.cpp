/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:20:02 by agachet           #+#    #+#             */
/*   Updated: 2021/09/29 18:53:15 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Creation de Scavtrap" << std::endl;
	return ;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Creation ""Default"" de Scavtrap" << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "Destruction de Scavtrap" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
	return ;
}
