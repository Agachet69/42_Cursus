/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:39:15 by agachet           #+#    #+#             */
/*   Updated: 2021/10/11 15:52:56 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(Cat const &);
		Cat	&operator=(Cat const &);
		virtual ~Cat();

		void makeSound() const;

	private:
		Brain *_Brain;
};

#endif
