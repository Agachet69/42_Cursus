/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:30:53 by agachet           #+#    #+#             */
/*   Updated: 2021/10/01 16:48:00 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Construction Animal Class" << std::endl;
	return ;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Constructeur de Copy" << std::endl;
	*this = copy;
	return ;
}

Animal	&Animal::operator=(Animal const &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->type = assignation.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destruction Animal Class" << std::endl;
	return ;
}

void	Animal::makeSound() const
{
	std::cout << "Animal make sound" << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	return (this->type);
}
