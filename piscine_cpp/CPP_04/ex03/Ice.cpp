/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:01:25 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:28:47 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice")
{
	return ;
}

Ice::Ice(std::string const &type) : _type(type)
{
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
