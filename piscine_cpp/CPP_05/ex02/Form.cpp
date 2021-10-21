/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:06:22 by agachet           #+#    #+#             */
/*   Updated: 2021/10/13 19:36:27 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Form::Form()
//{
//	return ;
//}

Form::Form(std::string name, int Gsign, int Gexec) : _name(name), _Gsign(Gsign), _Gexec(Gexec)
{
	_sign = 0;
	if (this->_Gsign < 1 || this->_Gexec < 1)
		throw Form::GradeTooHighException();
	if (this->_Gsign > 150 || this->_Gexec > 150)
		throw Form::GradeTooLowException();
	return ;
}

//Form::Form(Form const &copy)
//{
//	(*this) = copy;
//}

Form::~Form()
{
	return ;
}

Form	&Form::operator=(Form const &assignation)
{
	if (this != &assignation)
	{
		this->_sign = assignation._sign;
		//this->_name = assignation._name;
		//this->_Gexec = assignation._Gexec;
		//this->_Gsign = assignation._Gsign;
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

int Form::getGsign() const
{
	return (this->_Gsign);
}

int Form::getGexec() const
{
	return (this->_Gexec);
}

int Form::getSign() const
{
	return (this->_sign);
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (this->getGexec() < executor.getGrade())
		throw  Form::GradeTooLowException();
	if (executor.getGrade() < 1)
		throw Form::GradeTooHighException();
}

std::ostream	&operator<<(std::ostream &o, Form &Cls)
{
	o << "Le Form " << Cls.getName() << " peut être signé par un bureaucrate de grade " << Cls.getGsign();
	o << " minimum, il peut être executé par un bureaucrate de grade " << Cls.getGexec() << " minimum.";
	if (Cls.getSign() == 0)
		o << " Actuellement, le Form n'est pas signé." << std::endl;
	else
		o << " Actuellement, le Form signé." << std::endl;
	return (o);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

Form	&Form::beSigned(Bureaucrat &b)
{
	if (this->getGsign() < b.getGrade())
	{
		b.SignForm(*this);
		throw Form::GradeTooLowException();
	}
	else if (this->getGsign() >= b.getGrade())
	{
		this->_sign = 1;
		b.SignForm(*this);
		return (*this);
	}
	return (*this);
}

