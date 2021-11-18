/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:56:09 by agachet           #+#    #+#             */
/*   Updated: 2021/10/27 20:12:44 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
		std::string _type;

	public:
		Ice();
		Ice(std::string const & type);
		virtual ~Ice();
		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
