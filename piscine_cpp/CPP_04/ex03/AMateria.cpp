/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:16:22 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 16:26:40 by agachet          ###   ########.fr       */
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
