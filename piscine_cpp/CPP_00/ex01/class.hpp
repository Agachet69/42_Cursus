/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:22:29 by agachet           #+#    #+#             */
/*   Updated: 2021/10/26 15:22:16 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <string>

class Repertoire {

public:

	Repertoire(void);
	~Repertoire(void);

	void	add(Repertoire *test);
	void	search(Repertoire *test, int i);
	void	details(int i);

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	secret;
	std::string fname;
	std::string lname;
	std::string nname;
};

#endif //------------------------------------ Class Repertoire
