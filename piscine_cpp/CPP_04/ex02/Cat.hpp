/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:39:15 by agachet           #+#    #+#             */
/*   Updated: 2021/10/04 19:30:32 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal /*, virtual public Brain*/
{
	public:
		Cat();
		Cat(Cat const &);
		Cat	&operator=(Cat const &);
		virtual ~Cat();

		void makeSound() const;
		void setBrain(std::string *ideas);
		std::string getType() const;

	protected:
		std::string type;

	private:
		std::string *_Brain;
};

#endif
