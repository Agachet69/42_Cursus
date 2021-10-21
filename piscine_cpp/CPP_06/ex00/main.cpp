/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:29:11 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 19:20:26 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

int main(int argc,char **argv)
{
	char	c;
	int		i;
	double	d;
	float	f;
	std::string number;

	if (argc != 2)
	{
		std::cout << "Program takes one argument." << std::endl;
		return (0);
	}
	number = argv[1];
	if (strlen(argv[1]) == 1)
	{
		c = argv[1][0];
		if (c >= 48 && c <= 57)
			d = static_cast<double>(c - 48);
		else
			d = static_cast<double>(c);
	}
	else
	{
		try
		{
			d = std::stod(number);
		}
		catch (std::exception &e)
		{
			std::cout << "Not a valid value" << std::endl;
			return 0;
		}
	}
	c = static_cast<char>(d);
	if (d > 127 || d < 30 || std::isnan(d) == true)
		std::cout << "char: impossible"<< std::endl;
	else if (std::isprint(c) == 0)
		std::cout << "char: non displayable"<< std::endl;
	else
		std::cout << "char: " << c << std::endl;
	i = static_cast<int>(d);
	if (d > INT_MAX || d < INT_MIN || std::isnan(d) == true)
		std::cout << "int: impossible"<< std::endl;
	else
		std::cout << "int: " << i << std::endl;
	f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

}
