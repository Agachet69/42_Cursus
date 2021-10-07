/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:31:51 by agachet           #+#    #+#             */
/*   Updated: 2021/09/21 15:56:03 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	verif(int ac, char *av2, char *av3)
{
	std::string s1;
	std::string s2;

	if (ac != 4 || !av2 || !av3)
	{
		std::cout << "arguments incorrect" << std::endl;
		return (-1);
	}
	s1 = av2;
	s2 = av3;
	if (s1.size() == 0 || s2.size() == 0)
	{
		std::cout << "arguments incorrect" << std::endl;
		return (-1);
	}
	return (0);
}

int main(int ac, char **av)
{
	std::string NomDeFicher;
	std::string s1;
	std::string s2;
	std::string tmp;
	char a;

	if (verif(ac, av[2], av[3]) == -1)
		return (-1);
	s1 = av[2];
	s2 = av[3];
	NomDeFicher = av[1];
	std::ifstream Ficher_srcs(NomDeFicher);
	std::ofstream MonFichier(NomDeFicher += ".replace");
	int i;
	if (Ficher_srcs)
	{
		for (i = 0; Ficher_srcs.get(a); i++)
		{
			std::cout << i << std::endl;
			if (a == s1[i])
			{
				if (i + 1 == s1.size())
				{
					MonFichier << s2;
					tmp.clear();
					i = -1;
				}
				else
					tmp += a;
			}
			else
			{
				i = -1;
				if (tmp.size() == 0)
					MonFichier << a;
				else
				{
					MonFichier << tmp;
					tmp.clear();
					if (a != s1[0])
						MonFichier << a;
					else
					{
						tmp += a;
						i = 0;
					}
				}
			}
		}
	}
	else
		return (errno);
	return (0);
}
