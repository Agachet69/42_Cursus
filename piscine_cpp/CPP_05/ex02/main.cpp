/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/10/14 16:46:15 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "|||||||||||||||||||||||||||||||| TEST 1 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat Btest1("Gilbert", 20);
		Bureaucrat Btest111("Boss", 1);
		Form	*Ftest11 = new PresidentialPardonForm("Keryan");
		Ftest11->beSigned(Btest1);
		Btest111.executeForm(*Ftest11);
		delete Ftest11;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}


	std::cout << "|||||||||||||||||||||||||||||||| TEST 2 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat Btest2("Damien", 70);
		Bureaucrat Btest22("Boss", 1);
		Form	*Ftest22 = new RobotomyRequestForm("Keryan");
		Ftest22->beSigned(Btest2);
		Btest22.executeForm(*Ftest22);
		Btest22.executeForm(*Ftest22);
		Btest22.executeForm(*Ftest22);
		Btest22.executeForm(*Ftest22);
		Btest22.executeForm(*Ftest22);
		Btest22.executeForm(*Ftest22);
		delete Ftest22;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}


	std::cout << "|||||||||||||||||||||||||||||||| TEST 3 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat Btest3("Damien", 140);
		Bureaucrat Btest33("Boss", 19);
		Form	*Ftest33 = new ShrubberyCreationForm("Jardin");
		Ftest33->beSigned(Btest3);
		Btest33.executeForm(*Ftest33);
		delete Ftest33;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
}
