/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:43:36 by agachet           #+#    #+#             */
/*   Updated: 2021/10/04 18:13:24 by agachet          ###   ########.fr       */
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


	protected:
		std::string *ideas;
};

#endif
