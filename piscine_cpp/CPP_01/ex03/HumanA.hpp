/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:32:02 by agachet           #+#    #+#             */
/*   Updated: 2021/09/17 20:51:29 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_Weapon;

	public:
		HumanA(std::string name, Weapon &Weapon_name);
		~HumanA(void);
		void	setName(std::string name);
		void	attack();
};

#endif
