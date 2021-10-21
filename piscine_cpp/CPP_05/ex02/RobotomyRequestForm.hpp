/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:11:17 by agachet           #+#    #+#             */
/*   Updated: 2021/10/14 16:03:23 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class  RobotomyRequestForm : public Form
{
	private:
		std::string _target;
		int			i;

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
