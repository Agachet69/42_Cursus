/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:19 by agachet           #+#    #+#             */
/*   Updated: 2021/10/20 17:19:33 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename L, typename F>
void    iter(T *tab, L lenght, F (*func))
{
    for (int i = 0; i < lenght; i++)
      (*func)(tab[i]);
}

#endif
