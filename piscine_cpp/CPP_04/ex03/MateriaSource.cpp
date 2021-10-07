/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:23:05 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:29:51 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->srcs[i] = 0;
	return ;
}

MateriaSource::~MateriaSource()
{
	return ;
}

void		MateriaSource::learnMateria(AMateria *n)
{
	int i;

	for (i = 0; ((this->srcs[i] != 0) && i < 4); i++)
		;
	if (i < 4)
		this->srcs[i] = n->clone();
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i;

	for (i = 0; ((this->srcs[i] != 0) && i < 4); i++)
		;
	if (this->srcs[i - 1]->getType() == type)
		return (this->srcs[i - 1]->clone());
	return (0);

}
