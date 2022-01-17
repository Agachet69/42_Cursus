/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/01/17 20:36:29 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include "test.hpp"

int main()
{

	std::vector<int> test(8, 9);
	std::vector<int> test3(30, 8);

	test.push_back(5);

	std::vector<int>::iterator it = test.begin();
	std::vector<int>::iterator ite = test.end();
	--ite;

	test3.assign(it, ite);

	for (it = test3.begin(); it != test3.end(); ++it)
		std::cout << " " << *it;
		std::cout << "\n" << test3.capacity();
		std::cout << "\n" << test3.size();

	//	std::cout << std::endl;
//	std::cout << " \n";


//	std::cout << "\n ........................... MY VECTOR ................................... \n" << std::endl;

		std::cout << "\n\n\n\n\n\n";

	ft::vector<int> test9(8, 9);
	ft::vector<int> test4(30, 8);

	test9.push_back(5);

	ft::vector<int>::iterator itm = test9.begin();
	ft::vector<int>::iterator item = test9.end();
	--item;

	test4.assign(itm, item);

	for (itm = test4.begin(); itm != test4.end(); ++itm)
		std::cout << " " << *itm;
		std::cout << "\n" << test4.capacity();
		std::cout << "\n" << test4.size();


	//for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << " " << *it;
	//std::cout << " \n";


	//for (ft::vector<int>::iterator itee = test2.begin(); itee != test2.end(); ++itee)
	//	std::cout << ' ' << *itee;
}
