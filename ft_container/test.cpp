/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/01/13 19:34:08 by agachet          ###   ########.fr       */
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

//	test.push_back(5);

	//test.clear();
	//std::cout <<	test.capacity() << std::endl;
	//std::cout <<	test.size() << std::endl;

	//for (std::vector<int>::reverse_iterator it = test.rbegin(); it != test.rend(); ++it)
	//	std::cout << " " << *it;
	//	std::cout << std::endl;
//	std::cout << " \n";


//	std::cout << "\n ........................... MY VECTOR ................................... \n" << std::endl;

	ft::vector<int> test2(4, 7);
	test2.push_back(15);
	ft::vector<int>::iterator ite = test2.begin();
	ft::vector<int>::iterator it = test2.end();


	//for (ft::vector<int>::iterator iteee = test2.begin(); iteee != test2.end(); ++iteee)
	//	std::cout << " " << *iteee;


	ft::vector<int> test3(ite, it);



	for (ft::vector<int>::iterator itee = test3.begin(); itee != test3.end(); ++itee)
		std::cout << " " << *itee << itee;
	ft::vector<int> test4(test3);
	std::cout << std::endl;

	for (ft::vector<int>::iterator itt = test4.begin(); itt != test4.end(); ++itt)
		std::cout << " " << *itt << itt;
	//test3 = test;
	//std::cout <<	test3.capacity() << std::endl;
	//std::cout <<	test3.size() << std::endl;


	//for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << " " << *it;
	//std::cout << " \n";


	//for (ft::vector<int>::iterator itee = test2.begin(); itee != test2.end(); ++itee)
	//	std::cout << ' ' << *itee;
}
