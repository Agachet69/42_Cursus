/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUre.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:49:00 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:27:16 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : _type("cure")
{
	return ;
}

Cure::Cure(std::string const &type) : _type(type)
{
	return ;
}

Cure::~Cure()
{
	return ;
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

AMateria	*Cure::clone() const
{
	AMateria	*clone = new Cure(this->_type);
	return (clone);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
