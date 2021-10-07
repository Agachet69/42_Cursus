/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:27:01 by agachet           #+#    #+#             */
/*   Updated: 2021/10/04 18:13:17 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"
#include "string"

class Animal
{
	public:
		Animal();
		Animal(Animal const &);
		Animal	&operator=(Animal const &);
		virtual ~Animal();

		virtual void makeSound() const;
		virtual std::string getType() const;

	protected:
		std::string type;
};

#endif
