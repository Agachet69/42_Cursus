/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:50:35 by agachet           #+#    #+#             */
/*   Updated: 2021/10/04 19:31:12 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), type("Dog")
{
	int i = -1;

	std::cout << "Construction Dog Class" << std::endl;
	//this->_Brain = Brain::ideas;
	//while (++i < 50)
	//	_Brain[i] = "Dog";
	return ;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Constructeur de Copy" << std::endl;
	*this = copy;
	return ;
}

Dog	&Dog::operator=(Dog const &assignation)
{
	if (this != &assignation)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->type = assignation.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destruction Dog Class" << std::endl;
	return ;
}

void	Dog::makeSound() const
{
	std::cout << "WOUF WOUF" << std::endl;
	return ;
}

std::string	Dog::getType() const
{
	return (this->type);
}
