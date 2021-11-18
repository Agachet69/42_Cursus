/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:01:25 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 15:09:14 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}

Ice::Ice(std::string const &type) : AMateria("ice")
{
	this->_type = type;
	return ;
}

Ice::~Ice()
{
	return ;
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

AMateria		*Ice::clone() const
{
	AMateria *clone = new Ice(this->_type);
	return clone;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
