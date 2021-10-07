/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:28:50 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:26:51 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	int i;

	for (i = 0; i < 4; i++)
		this->Inventory[i] = 0;
	return ;
}

Character::~Character()
{
	int i;
	for (i = 0; i < 4; i++)
		if (this->Inventory[i] != 0)
			delete Inventory[i];
	return ;
}

std::string	const &Character::getName() const
{
	return (this->_name);
}

void		Character::equip(AMateria *m)
{
	int i;

	for (i = 0; ((this->Inventory[i] != 0) && i < 4); i++)
		this->Inventory[i] = 0;
	if ((i < 4) && (m))
		this->Inventory[i] = m;
}

void		Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->Inventory[idx] = 0;
}

void		Character::use(int idx, ICharacter &target)
{
	if ((idx >= 0 && idx < 4) && this->Inventory[idx] != 0)
		this->Inventory[idx]->use(target);
	return ;
}
