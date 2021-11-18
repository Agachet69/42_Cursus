/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:19 by agachet           #+#    #+#             */
/*   Updated: 2021/11/08 16:21:45 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template< typename Tadd, typename Tlenght>
void iter(Tadd const *tab, Tlenght lenght, void (*fct)(Tadd const &tab))
{
	for (int i = 0; i < lenght; i++)
	{
		(*fct)(tab[i]);
	}
}
#endif
