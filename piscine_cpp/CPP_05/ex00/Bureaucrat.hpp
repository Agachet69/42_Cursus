/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:58:26 by agachet           #+#    #+#             */
/*   Updated: 2021/10/07 19:38:56 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &);

#endif
