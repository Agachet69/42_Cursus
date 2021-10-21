/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:11:39 by agachet           #+#    #+#             */
/*   Updated: 2021/10/13 20:19:18 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	if (this->getGexec() >= executor.getGrade() && this->getSign() == 1)
	{
		std::cout << this->_target << " a été pardonnée par Zafod Beeblebrox." << std::endl;
	}
}
