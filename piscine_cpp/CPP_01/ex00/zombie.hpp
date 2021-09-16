/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:21:43 by agachet           #+#    #+#             */
/*   Updated: 2021/09/15 19:34:28 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
				std::string _name;

	public:
				Zombie(std::string name) :_name(name)
				{
					std::cout << "<name> " << this->_name << std::endl;
				}

				~Zombie()
				{
					std::cout << this->_name << " is dead." << std::endl;
				}

};

#endif
