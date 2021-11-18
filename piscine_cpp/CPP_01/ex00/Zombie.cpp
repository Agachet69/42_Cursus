/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:15:58 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 17:31:54 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." <<std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead." << std::endl;
	return;
}
