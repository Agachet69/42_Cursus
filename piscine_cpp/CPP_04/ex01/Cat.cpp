/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:20:55 by agachet           #+#    #+#             */
/*   Updated: 2021/10/05 15:41:07 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), type("Cat")
{
	int i = 49;

	std::cout << "Construction Cat Class" << std::endl;
	this->ideas = new Brain();
	while (++i < 100)
		ideas[i] = "Cat";
	return ;
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Constructeur de Copy" << std::endl;
	*this = copy;
	return ;
}

Cat	&Cat::operator=(Cat const &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->type = assignation.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destruction Cat Class" << std::endl;
	delete this->ideas;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}

std::string	Cat::getType() const
{
	return (this->type);
}
