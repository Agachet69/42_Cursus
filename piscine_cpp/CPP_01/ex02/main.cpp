/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:00:24 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 17:44:38 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = ("HI THIS IS BRAIN");
	std::string *strPTR = &str;
	std::string &strREF = str;
	std::cout << "str:    " << &str << std::endl;
	std::cout << "strPTR: " << strPTR << std::endl;
	std::cout << "strREF: " << &strREF << std::endl << std::endl;
	std::cout << "strPTR: " << *strPTR << std::endl;
	std::cout << "strREF: " << strREF << std::endl;
	return (0);
}
