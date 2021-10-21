/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:13:35 by agachet           #+#    #+#             */
/*   Updated: 2021/10/13 19:36:33 by agachet          ###   ########.fr       */
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
		virtual ~Form();
		Form	&operator=(Form const &);

		std::string getName()const;
		int getGsign()const;
		int getGexec()const;
		int getSign()const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
