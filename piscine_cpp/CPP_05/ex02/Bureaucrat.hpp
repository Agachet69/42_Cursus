/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:58:26 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 20:23:27 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int note);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &);

		std::string	getName() const;
		int			getGrade() const;
		void		Increment();
		void		Decrement();
		void		SignForm(Form const&) const;
		void		executeForm(Form const &form);

		class GradeTooHighException: public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		int				_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &);

#endif
