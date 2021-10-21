/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:11:12 by agachet           #+#    #+#             */
/*   Updated: 2021/10/14 18:35:56 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target), i(0)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
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
