/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:02:52 by agachet           #+#    #+#             */
/*   Updated: 2021/10/05 15:11:09 by agachet          ###   ########.fr       */
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
		this->ideas = assignation.ideas;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destruction de Brain" << std::endl;
	return ;
}

