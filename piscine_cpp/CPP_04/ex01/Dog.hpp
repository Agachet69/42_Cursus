/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:12 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 15:54:46 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal, virtual public Brain
{
	public:
		Dog();
		Dog(Dog const &);
		Dog	&operator=(Dog const &);
		virtual ~Dog();

		void makeSound() const;

	private:
		Brain *_Brain;
};

#endif
