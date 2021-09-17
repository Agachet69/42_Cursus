/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:55:34 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 17:55:04 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " se rendort." << std::endl;
	return ;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce()
{
	std::cout << this->_name << " se réveil." << std::endl;
}
