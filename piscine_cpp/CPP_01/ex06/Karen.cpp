/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:32:40 by agachet           #+#    #+#             */
/*   Updated: 2021/09/21 17:44:45 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!";
			std::cout << std::endl << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to askfor it!";
			std::cout << std::endl << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.";
			std::cout << std::endl << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			std::cout << "This is unacceptable, I want to speak to the manager now.";
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

Karen::~Karen()
{
	return ;
}
