/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:16:22 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:26:15 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
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

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	if (_type.compare("ice") == 0)
		std::cout << "* shoots an ice bolt at bob *" << std::endl;
	else if (_type.compare("cure") == 0)
		std::cout << "* heals bob's wounds *" << std::endl;
	return ;
}
