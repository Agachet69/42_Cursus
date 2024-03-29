/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:23:25 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 20:26:10 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int note) : _name(name), _grade(note)
{
		if (note < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (note > 150)
			throw Bureaucrat::GradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &assignation)
{
	if (&assignation != this)
		this->_grade = assignation.getGrade();
	return (*this);
}

void	Bureaucrat::Increment()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::Decrement()
{
	if ((this->_grade + 1) > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << " bureaucrat grade " << src.getGrade() << "." << std::endl;
	return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low !");
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::SignForm(Form const &f) const
{
	if (f.getSign() == 1)
		std::cout << this->_name << " signs " << f.getName() << std::endl;
	else if (f.getSign() == 0)
		std::cout << this->_name << " cannot sign " << f.getName() << " because his grade is to low !" << std::endl;
}

void		Bureaucrat::executeForm(Form const &form)
{
	if (form.getGexec() < this->getGrade())
		throw  Form::GradeTooLowException();
	else if(this->getGrade() < 1)
		throw Form::GradeTooHighException();
	if (form.getGexec() >= this->getGrade() && form.getSign() == 1)
	{
		std::cout << this->getName() << " execute " << form.getName() << std::endl;
	}
	form.execute(*this);
}
