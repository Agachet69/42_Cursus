/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:39:15 by agachet           #+#    #+#             */
/*   Updated: 2021/10/29 18:43:33 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &);
		Cat	&operator=(Cat const &);
		virtual ~Cat();

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();

		void makeSound() const;

	protected:
		std::string type;
};

#endif
