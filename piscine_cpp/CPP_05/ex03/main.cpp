/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/11/02 17:54:00 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{

	std::cout << "|||||||||||||||||||||||||||||||| TEST 1 ||||||||||||||||||||||||||" << std::endl;

	try
	{
		Bureaucrat Btest1("Michel", 4);
		Intern test1;
		Form *Ftest1;
		Ftest1 = test1.makeForm("presidential pardon", "kiki");
		Ftest1->beSigned(Btest1);
		Btest1.executeForm(*Ftest1);
		delete Ftest1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 2 ||||||||||||||||||||||||||" << std::endl;

	try
	{
		Bureaucrat Btest2("Martine", 2);
		Intern test2;
		Form *Ftest2;
		Ftest2 = test2.makeForm("bizarre", "kiki");
		Ftest2->beSigned(Btest2);
		Btest2.executeForm(*Ftest2);
		delete Ftest2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
}
