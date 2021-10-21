/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:31:19 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 18:45:06 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//int main()
//{
//	Span t(1);
//	try
//	{
//		t.addNumber(159);
//		//t.addNumber(156);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(-158545454);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(18);
//		//t.addNumber(158);
//		//t.addNumber(15);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(158);
//		//t.addNumber(-58);
//		//t.addNumber(158);
//		//t.addNumber(-151);
//		//t.addNumber(17);
//		//t.addNumber(154);
//		std::cout << t.longestSpan() << std::endl;
//	}
//	catch(const std::length_error & e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//}

int main()
{
Span sp = Span(5);
sp.addNumber(5);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}
