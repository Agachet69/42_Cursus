/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:59:37 by agachet           #+#    #+#             */
/*   Updated: 2021/09/27 20:16:34 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap test("LA D");
	test.attack("Koba");
	test.takeDamage(45);
	test.beRepaired(41);
	test.guardGate();
	return (0);
}
