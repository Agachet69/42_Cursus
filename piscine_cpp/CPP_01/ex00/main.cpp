/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:31:54 by agachet           #+#    #+#             */
/*   Updated: 2021/09/16 14:56:37 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie ted("Teeeeeed");

	Zombie *joe = newZombie("Jooooe");
	randomChump("Kyyyyyyky");
	delete joe;
	return (0);
}
