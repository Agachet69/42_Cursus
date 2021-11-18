/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Repertoire_class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:26:38 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 15:22:34 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "class.hpp"

std::string	ft_affichage(std::string *str)
{
	int espace;
	std::string str2;
	std::string tmp;
	std::string tmp2;
	int i;

	if ((*str).size() < 1)
		(*str = "(vide)");
	tmp = *str;
	if ((*str).size() > 10)
		(*str).replace(9, (*str).size() - 9, ".");
	else if ((*str).size() < 10)
	{
		espace = 10 - (*str).size();
		for (i = 0; i < espace; i++)
		{
			 str2.append(1u,' ');
		}
		str2 += (*str);
		return (str2);
	}
	tmp2 = (*str);
	(*str) = tmp;
	return (tmp2);
}

Repertoire::Repertoire(void)
{
	return ;
}

Repertoire::~Repertoire(void)
{
	return ;
}

void Repertoire::details(int i)
{
	std::cout << std::endl << "first name: " << this[i].fname << std::endl;
	std::cout << "last name: " << this[i].lname << std::endl;
	std::cout << "nickname: " << this[i].nname << std::endl;
	if ((int)this[i].number.find_first_not_of("0123456789") != -1 || this[i].number.size() != 10)
		std::cout << "number: non valide" << std::endl;
	else
		std::cout << "number: " << this[i].number << std::endl;
	std::cout << "darkest secret: ";
	if (this[i].secret.size() == 0)
		std::cout << "(vide)" << std::endl << std::endl;
	else
		std::cout << this[i].secret << std::endl << std::endl;
}

void Repertoire::add(Repertoire *test)
{
	std::cout << "first name :";
	std::getline (std::cin, test->fname);
	test->first_name = ft_affichage(&test->fname);
	std::cout << "last name :";
	std::getline (std::cin, test->lname);
	test->last_name = ft_affichage(&test->lname);
	std::cout << "nickname :";
	std::getline (std::cin, test->nname);
	test->nickname = ft_affichage(&test->nname);
	std::cout << "number :";
	std::getline (std::cin, test->number);
	std::cout << "secret :";
	std::getline (std::cin, test->secret);
}

void Repertoire::search(Repertoire *test, int i)
{
	int index;
	std::string contact;

	std::cout << std::endl << "     index|";
	std::cout << "first name|";
	std::cout << " last name|";
	std::cout << "  nickname|" << std::endl;
	for (index = 0; index <= i; index++)
	{
		std::cout << "         " << index + 1 << "|";
		std::cout << test[index].first_name << "|";
		std::cout << test[index].last_name << "|";
		std::cout << test[index].nickname << "|"  << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-> Pour plus de détails, veuillez entrer l'index du contact recherché: ";
	std::getline (std::cin, contact);
	while (contact.size() == 0 || (int)contact.find_first_not_of("12345678") != -1)
	{
		std::cout << "-> Attention, mauvais format" << std::endl;
		std::cout << "-> ";
		std::getline (std::cin, contact);
	}
	if (std::stoi(contact) < index + 1)
		details(std::stoi(contact) - 1);
	else
		std::cout << "-> Ce contact n'existe pas." << std::endl;
}
