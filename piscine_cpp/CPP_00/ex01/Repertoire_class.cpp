/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Repertoire_class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:26:38 by agachet           #+#    #+#             */
/*   Updated: 2021/09/15 16:58:08 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "class.hpp"

std::string	ft_affichage(std::string str)
{
	int espace;
	std::string str2;
	int i;

	if (str.size() > 10)
		str.replace(9, str.size() - 9, ".");
	else if (str.size() < 10)
	{
		espace = 10 - str.size();
		for (i = 0; i < espace; i++)
		{
			 str2.append(1u,' ');
		}
		str2 += str;
		return (str2);
	}
	return (str);
}

Repertoire::Repertoire(void)
{
	return ;
}

Repertoire::~Repertoire(void)
{
	return ;
}

void Repertoire::add(Repertoire *test)
{
	std::string str;

	std::cout << "first name :";
	std::cin >> str;
	test->first_name = ft_affichage(str);
	std::cout << "last name :";
	std::cin >> str;
	test->last_name = ft_affichage(str);
	std::cout << "nickname :";
	std::cin >> str;
	test->nickname = ft_affichage(str);
	std::cout << "number :";
	std::cin >> test->number;
	std::cout << "secret :";
	std::cin >> test->secret;
}

void Repertoire::search(Repertoire *test, int i)
{
	int index;

	std::cout << "     index|";
	std::cout << "first name|";
	std::cout << " last name|";
	std::cout << "  nickname|" << std::endl;
	for (index = 0; index <= i; index++)
	{
		std::cout << "         " << index + 1 << "|";
		std::cout << test[index].first_name << "|";
		std::cout << test[index].last_name << "|";
		std::cout << test[index].nickname << "|" << std::endl;
	}
}
