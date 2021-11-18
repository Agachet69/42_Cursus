/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:21:32 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 20:01:27 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(ClapTrap const &);
			ClapTrap	&operator=(ClapTrap const &);
			~ClapTrap(void);

			void attack(std::string const & target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

	protected:
			std::string _name;
			int			_hitpoints;
			int			_energy_points;
			int			_attack_damage;
};

#endif
