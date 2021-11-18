/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:28:50 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 19:43:55 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

Character::Character(std::string name) : _name(name)
{
	int i;

	for (i = 0; i < 4; i++)
		this->Inventory[i] = 0;
	return ;
}

Character::Character() : _name("Default")
{
	int i;

	for (i = 0; i < 4; i++)
		this->Inventory[i] = 0;
	return ;
}

Character::Character(Character const &copy)
{
	int i;
	this->_name = copy._name;
	for (i = 0; i < 4; i++)
	{
		if (copy.Inventory[i]->getType() == "cure")
			this->Inventory[i] = new Cure;
		else if (copy.Inventory[i]->getType() == "ice")
			this->Inventory[i] = new Ice;
	}

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
		;
	if ((i < 4) && (m))
	{
		this->Inventory[i] = m;
	}
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
