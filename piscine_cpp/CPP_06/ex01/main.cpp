/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:17:13 by agachet           #+#    #+#             */
/*   Updated: 2021/10/19 17:24:01 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>

typedef struct Data_t
{
	int	j;
}				Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data test;
	Data *test2;

	std::cout << &test << std::endl;
	(test2) = deserialize((serialize(&test)));
	std::cout << test2 << std::endl;
	test2->j = 0;
	std::cout << test2->j << std::endl;
	test.j = 2;
	std::cout << test2->j << std::endl;
	return (0);
}
