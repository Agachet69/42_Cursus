/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:11:12 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 20:31:37 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(), _target("Default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &ass)
{
	if (&ass != this)
		this->_target = ass._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	Form::execute(executor);
	if (this->getGexec() >= executor.getGrade() && this->getSign() == 1)
	{
		if (rand() % 2 == 0)
			std::cout << this->_target << " a bien été robotomizée !" << std::endl;
		else
			std::cout << this->_target << " n'a pas été robotomizée " << std::endl;
	}
}
