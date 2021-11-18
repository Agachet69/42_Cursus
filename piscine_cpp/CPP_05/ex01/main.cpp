/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 20:02:52 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "|||||||||||||||||||||||||||||||| TEST 1 ||||||||||||||||||||||||||" << std::endl;
		Bureaucrat test1("Gilbert", 75);
		Form	test11("Dossier1", 28, 10);
		std::cout << test11;
		test11.beSigned(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	try
	{
		std::cout << "|||||||||||||||||||||||||||||||| TEST 2 ||||||||||||||||||||||||||" << std::endl;
		Bureaucrat test2("Sylvain", 12);
		Form	test22("Dossier2", 20, 15);
		std::cout << test22;
		test22.beSigned(test2);
		std::cout << test22;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "|||||||||||||||||||||||||||||||| TEST 3 ||||||||||||||||||||||||||" << std::endl;
		Bureaucrat test3("Fabienne", 150);
		std::cout << test3 << std::endl;
		Form	test22("Dossier2", 220, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}
}
