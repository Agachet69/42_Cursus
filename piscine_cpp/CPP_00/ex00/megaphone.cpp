/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:58:46 by agachet           #+#    #+#             */
/*   Updated: 2021/09/13 17:50:30 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (int ac, char **av)
{
	std::string str;
	int i;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while(av[++i] != NULL)
		{
			str = av[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}


