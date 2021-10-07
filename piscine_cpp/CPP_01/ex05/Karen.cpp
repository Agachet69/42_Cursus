/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:18:44 by agachet           #+#    #+#             */
/*   Updated: 2021/09/21 16:49:54 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	this->tab[0] = &Karen::debug;
	this->tab[1] = &Karen::info;
	this->tab[2] = &Karen::warning;
	this->tab[3] = &Karen::error;
	return ;
}

Karen::~Karen()
{
	return;
}

void Karen::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*tab[i])();
	}
	return ;
}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!";
	std::cout << std::endl;
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to askfor it!";
	std::cout << std::endl;
}

void Karen::warning()
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.";
	std::cout << std::endl;
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}
