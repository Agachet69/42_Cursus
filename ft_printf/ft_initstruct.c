/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:04:40 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:24 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initstruct(t_printf *res)
{
	res->car = -1;
	res->struc = 0;
	res->i = 0;
	res->stockstar = 0;
	res->stockzero = 0;
	res->stockmoins = 0;
	res->stockspaces = 0;
	res->stockprecision = -1;
	res->compteur_putnbr = 0;
	res->putnbr_zero = 0;
	res->pourcent = 0;
	res->ireturn = 0;
	res->cas_zero_c = 0;
}

void	ft_re_zero(t_printf *res)
{
	res->car = 0;
	res->struc = 0;
	res->stockstar = 0;
	res->stockzero = 0;
	res->stockmoins = 0;
	res->stockspaces = 0;
	res->stockprecision = -1;
	res->compteur_putnbr = 0;
	res->putnbr_zero = 0;
	res->cas_zero_c = 0;
}
