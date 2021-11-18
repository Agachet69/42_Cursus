/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:50:34 by agachet           #+#    #+#             */
/*   Updated: 2021/10/27 18:47:45 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "Type : ";
	std::cout << j->getType() << " " << std::endl;
	std::cout << "Type : ";
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "MakeSound Cat : ";
	i->makeSound();
	std::cout << std::endl;
	std::cout << "MakeSound Dog : ";
	j->makeSound();
	std::cout << std::endl;
	delete j;
	delete i;
	return (0);

}
