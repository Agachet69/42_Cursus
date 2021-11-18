/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:54:35 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 17:51:57 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap bibi("La Squale");
	bibi.highFivesGuys();
	bibi.attack("Moha");
	bibi.beRepaired(8);
	return (0);
}
