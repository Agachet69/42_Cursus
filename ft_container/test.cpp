/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2021/12/23 19:13:49 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include "test.hpp"

int main()
{

//	std::vector<int> test(8, 15);
	//std::vector<int> test3(20, 150);

	//test.clear();
	//std::cout <<	test.capacity() << std::endl;
	//std::cout <<	test.size() << std::endl;


	//for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << " " << *it;
	//std::cout << " \n";


//	std::cout << "\n ........................... MY VECTOR ................................... \n" << std::endl;

	ft::vector<int> test(8, 15);
	ft::vector<int> test3;

	test3 = test;
	std::cout <<	test3.capacity() << std::endl;
	std::cout <<	test3.size() << std::endl;


	//for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << " " << *it;
	//std::cout << " \n";


	//for (ft::vector<int>::iterator itee = test2.begin(); itee != test2.end(); ++itee)
	//	std::cout << ' ' << *itee;
}
