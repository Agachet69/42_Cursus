/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:35:27 by agachet           #+#    #+#             */
/*   Updated: 2021/10/19 19:04:12 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
void	easyfind(T cont, int occurence)
{
	std::vector<int>::iterator ret;

	ret = std::find (cont.begin(), cont.end(), occurence);
	if (ret != cont.end())
		std::cout << "Trouvé !" << std::endl;
	else
		std::cout << "L'occurence n'a pas été trouvée..." << std::endl;
}

#endif
