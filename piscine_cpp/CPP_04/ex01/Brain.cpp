/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:02:52 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 16:19:25 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Construction de Brain" << std::endl;
	return ;
}

Brain::Brain(Brain const &copy)
{
	*this = copy;
	return;
}

Brain	&Brain::operator=(Brain const &assignation)
{
	if (this != &assignation)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = assignation.ideas[i];
	}
	return (*this);
}

std::string	Brain::getId(int i)
{
	return (this->ideas[i]);
}

void	Brain::setId(int i, std::string brain)
{
	this->ideas[i] = brain;
}

Brain::~Brain()
{
	std::cout << "Destruction de Brain" << std::endl;
	return ;
}

