/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:21:13 by agachet           #+#    #+#             */
/*   Updated: 2021/10/19 19:04:18 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> test1(10, 15);
		easyfind(test1, 8);
	test1.push_back(8);
		easyfind(test1, 8);

	//try
	//{
	//}
	//catch(std::exception &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	return (0);
}
