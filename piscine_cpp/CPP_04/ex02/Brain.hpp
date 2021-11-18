/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:43:36 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 16:09:46 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const &);
		Brain &operator=(Brain const &);
		virtual ~Brain();

		std::string getId(int i);
		void	setId(int i, std::string brain);


	protected:
		std::string ideas[100];
};

#endif
