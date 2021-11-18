/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 19:18:26 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "|||||||||||||||||||||||||||||||| TEST 1 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat test1("Gilbert", 75);
		std::cout << test1 << std::endl;
		test1.Decrement();
		std::cout << test1 << std::endl;
		test1.Increment();
		std::cout << test1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 2 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat test2("Fabienne", 150);
		std::cout << test2 << std::endl;
		test2.Decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 3 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat test3("Bernard", 1);
		std::cout << test3 << std::endl;
		test3.Increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 4 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat test4("Sylvie", 158);
	}
	catch(const std::exception& e)
	{
		std::cout << "Sylvie ";
		std::cerr << e.what() << '\n' << std::endl;
	}

	std::cout << "|||||||||||||||||||||||||||||||| TEST 5 ||||||||||||||||||||||||||" << std::endl;
	try
	{
		Bureaucrat test5("Mike", -12);
	}
	catch(const std::exception& e)
	{
		std::cout << "Mike ";
		std::cerr << e.what() << '\n' << std::endl;
	}


}
