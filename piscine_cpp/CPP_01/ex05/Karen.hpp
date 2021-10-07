/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:02:43 by agachet           #+#    #+#             */
/*   Updated: 2021/09/21 16:45:09 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	public:

	Karen(void);
	~Karen(void);
	void complain( std::string level );

	private:

	void (Karen::*tab[4])(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif
