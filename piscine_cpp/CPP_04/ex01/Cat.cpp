/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:20:55 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 16:55:54 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Construction Cat Class" << std::endl;
	this->_Brain = new Brain();
	return ;
}

Cat::Cat(Cat const &copy)
{
	this->type = copy.type;
	this->_Brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->_Brain->setId(i, copy._Brain->getId(i));
	std::cout << "Deep Constructeur de Copy" << std::endl;
	*this = copy;
	return ;
}

Cat	&Cat::operator=(Cat const &assignation)
{
	this->type = assignation.type;
	for (int i = 0; i < 100; i++)
		this->_Brain->setId(i, assignation._Brain->getId(i));
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destruction Cat Class" << std::endl;
	delete this->_Brain;
	return ;
}

void	Cat::makeSound() const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}
