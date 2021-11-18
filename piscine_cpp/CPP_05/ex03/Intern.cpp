/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:26:35 by agachet           #+#    #+#             */
/*   Updated: 2021/11/08 15:40:38 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->tab[0] = &Intern::Shrubbery;
	this->tab[1] = &Intern::Request;
	this->tab[2] = &Intern::President;
	return ;
}

Intern::~Intern()
{
	return ;
}

Form	*Intern::makeForm(std::string FormName, std::string target)
{
	std::string NameF[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (NameF[i] == FormName)
			return (this->*tab[i])(target);
	}
	throw	Intern::FormInconnuException();
	Form *b;
	return (b);
}

Form	*Intern::Shrubbery(std::string target)
{
	Form *ret = new ShrubberyCreationForm(target);
	std::cout << "Intern creates ShrubberyCreates Form." << std::endl;
	return (ret);
}

Form	*Intern::Request(std::string target)
{
	Form *ret = new RobotomyRequestForm(target);
	std::cout << "Intern creates RobotomyRequest Form." << std::endl;
	return (ret);
}

Form	*Intern::President(std::string target)
{
	Form *ret = new PresidentialPardonForm(target);
	std::cout << "Intern creates PresidentialPardon Form." << std::endl;
	return (ret);
}

const char *Intern::FormInconnuException::what() const throw()
{
	return ("Form inconnu.");
}
