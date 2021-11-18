/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:16:22 by agachet           #+#    #+#             */
/*   Updated: 2021/10/28 17:37:05 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	return ;
}

AMateria::~AMateria()
{
	return ;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &assignation)
{
	if (this != &assignation)
	{
		this->_type = assignation._type;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}
