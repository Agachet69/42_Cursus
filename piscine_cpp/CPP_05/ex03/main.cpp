/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:24:12 by agachet           #+#    #+#             */
/*   Updated: 2021/10/14 19:12:33 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat Btest1("Michel", 4);
		Intern test1;
		Form *Ftest1;
		Ftest1 = test1.makeForm("presidential pardon", "kiki");
		Ftest1->beSigned(Btest1);
		Btest1.executeForm(*Ftest1);
		delete Ftest1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

}
