/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:44:50 by agachet           #+#    #+#             */
/*   Updated: 2021/10/06 17:27:28 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	protected:
		std::string _type;

	public:
		Cure();
		Cure(std::string const &type);
		~Cure();
		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
