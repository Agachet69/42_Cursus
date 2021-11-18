/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:27:37 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 15:23:16 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"



int main()
{
	int i;
	std::string str;
	Repertoire aa[8];

	i = -1;
	while (std::cout << "-> ENTREZ 'ADD' 'SEARCH' ou 'EXIT': " \
	&& std::getline (std::cin, str) && str.compare("EXIT") != 0)
	{
		if (str.compare("ADD") == 0)
		{
			if (i < 7)
				i++;
			aa[i].add(&aa[i]);
		}
		if (str.compare("SEARCH") == 0)
			aa->search(aa, i);
	}
	return (0);
}
