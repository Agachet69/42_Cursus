/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:10:52 by agachet           #+#    #+#             */
/*   Updated: 2021/10/14 16:31:31 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
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

