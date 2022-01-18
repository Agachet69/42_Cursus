/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/01/18 20:50:29 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include "test.hpp"
#include "stack.hpp"

int main()
{

	ft::stack<int> test;
	test.push(1);
	test.push(5);
	test.push(18);
std::cout << test.top();
test.pop();
std::cout << test.top();
//	std::vector<int> test(2, 9);
//	std::vector<int> test3(8, 8);

//	test.push_back(5);

//	std::vector<int>::iterator it = test.begin();
//	std::vector<int>::iterator itp = test.begin();

//	std::vector<int>::iterator ite = test.end();
//	--ite;

//	test3.insert(itp, it, ite);

////	for (it = test3.begin(); it != test3.end(); ++it)
////		std::cout << " " << *it;
//		std::cout << "\n" << test3.capacity();
//		std::cout << "\n" << test3.size();

	//	std::cout << std::endl;
//	std::cout << " \n";


//	std::cout << "\n ........................... MY VECTOR ................................... \n" << std::endl;

std::cout << "\n\n";

ft::stack<int> test2;
	test2.push(1);
	test2.push(5);

ft::stack<int> test3;
	test3.push(15);
	test3.push(54);

bool i = test3 == test2;
	std::cout << i;


	//for (ft::vector<int>::iterator itee = test2.begin(); itee != test2.end(); ++itee)
	//	std::cout << ' ' << *itee;
}
