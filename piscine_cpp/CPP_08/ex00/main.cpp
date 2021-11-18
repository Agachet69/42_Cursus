/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:21:13 by agachet           #+#    #+#             */
/*   Updated: 2021/11/08 16:25:28 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> test1(10, 15);
	test1.push_back(-8);
		easyfind(test1, 8);
	test1.push_back(8);
		easyfind(test1, 8);
	return (0);
}
