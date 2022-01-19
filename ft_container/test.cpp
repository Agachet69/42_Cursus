/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:50:06 by agachet           #+#    #+#             */
/*   Updated: 2022/01/19 18:48:40 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "test.hpp"
#include "stack.hpp"

int main()
{
	ft::vector<int> test8;

	ft::stack<int> test;
	test.push(1);
	test.push(5);
	test.push(18);
	std::cout << test.top();
	test.pop();
	std::cout << test.top();

std::cout << "\n\n ........................... My Container ................................... \n" << std::endl;

std::cout << "\n\n";

ft::stack<int> test2;
	test2.push(19);
	test2.push(58);

ft::stack<int> test3;
	test3.push(194);
	test3.push(588);

bool i = test3 >= test2;
	std::cout << i;


}
