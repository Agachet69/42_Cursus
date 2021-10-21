/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 19:57:48 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "|||||||||||||||||||||||||||||||| TEST 1 ||||||||||||||||||||||||||" << std::endl;

	Bureaucrat test1("Gilbert", 75);
	Form	test11("Dossier1", 28, 10);
	std::cout << test11;

	try
	{
		test11.beSigned(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 2 ||||||||||||||||||||||||||" << std::endl;
	Bureaucrat test2("Sylvain", 12);
	Form	test22("Dossier2", 28, 15);
	std::cout << test22;
	try
	{
		test22.beSigned(test2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//try
	//{
	//	Bureaucrat test2("Fabienne", 150);
	//	std::cout << test2 << std::endl;
	//	test2.Decrement();
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n' << std::endl;
	//}
}
