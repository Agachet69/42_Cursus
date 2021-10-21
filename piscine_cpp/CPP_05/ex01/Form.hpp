/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:13:35 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 19:40:09 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		int _sign;
		const int _Gsign;
		const int _Gexec;

	public:
		Form();
		Form(std::string name, int Gsign, int Gexec);
		Form(Form const &copy);
		~Form();
		Form	&operator=(Form const &);

		std::string getName();
		int getGsign();
		int getGexec();
		int getSign();

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	Form	&beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &o, Form &);

#endif
