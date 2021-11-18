/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:50:34 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 18:56:49 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal *tab[100];

	for (int i = 0; i < 50; i++)
		tab[i] = new Cat;
	for (int i = 50; i < 100; i++)
		tab[i] = new Dog;
	for (int i = 0; i < 100; i++)
		delete tab[i];

	std::cout << "\n\n\n\n" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
}
