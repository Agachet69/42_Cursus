/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:20:55 by agachet           #+#    #+#             */
/*   Updated: 2021/10/05 15:29:30 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), type("Cat")
{
	std::cout << "Construction Cat Class" << std::endl;
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

WrongCat::WrongCat() : type("Animal")
{
	std::cout << "Construction Cat Class" << std::endl;
	return ;
}

void	WrongCat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "Destruction Cat Class" << std::endl;
	return ;
}
