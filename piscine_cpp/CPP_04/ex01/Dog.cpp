/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:50:35 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 16:55:14 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Construction Dog Class" << std::endl;
	this->_Brain = new Brain;
	return ;
}

Dog::Dog(Dog const &copy)
{
	this->type = copy.type;
	this->_Brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->_Brain->setId(i, copy._Brain->getId(i));
	std::cout << "Deep Constructeur de Copy" << std::endl;
	*this = copy;
	return ;
}

Dog	&Dog::operator=(Dog const &assignation)
{
	this->type = assignation.type;
	for (int i = 0; i < 100; i++)
		this->_Brain->setId(i, assignation._Brain->getId(i));
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destruction Dog Class" << std::endl;
	delete this->_Brain;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "WOUF WOUF" << std::endl;
	return ;
}
