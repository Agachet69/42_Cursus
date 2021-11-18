/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:10:52 by agachet           #+#    #+#             */
/*   Updated: 2021/11/04 20:30:24 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target("Default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ass)
{
	if (&ass != this)
		this->_target = ass._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std:: string NomFichier;
	if (this->getGexec() >= executor.getGrade() && this->getSign() == 1)
	{
		NomFichier = this->_target;
		NomFichier += "_shrubbery";
		std::ofstream MonFichier(NomFichier);
		MonFichier << "       _-_" << std::endl;
	  	MonFichier << "    /~~   ~~\\" << std::endl;
		MonFichier << " /~~   🍎     ~~\\" << std::endl;
		MonFichier << "{  🍎         🍎 } " << std::endl;
	 	MonFichier << " \\  _-     -_  /" << std::endl;
		MonFichier << "   ~  \\\\ //  ~" << std::endl;
		MonFichier << "_- -   | | _- _" << std::endl;
	 	MonFichier << "  _ -  | |   -_" << std::endl;
	 	MonFichier << "      // \\\\" << std::endl;
	}

}
