/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:07:57 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:30:18 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	//src->learnMateria(new Ice());
	//src->learnMateria(new Cure());
	//ICharacter* me = new Character("me");
	//AMateria* tmp;
	//tmp = src->createMateria("ice");
	//me->equip(tmp);
	//tmp = src->createMateria("cure");
	//me->equip(tmp);
	//ICharacter* bob = new Character("bob");
	//me->use(0, *bob);
	//me->use(1, *bob);
	//delete bob;
	//delete me;
	//delete src;
	return 0;
}
