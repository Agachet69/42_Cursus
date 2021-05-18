/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_moins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:41:12 by agachet           #+#    #+#             */
/*   Updated: 2020/12/22 15:44:05 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_moins(t_printf *res)
{
	int		i;
	char	*ret;

	i = ft_strlen(res->struc);
	i = i + res->cas_zero_c;
	if (res->stockmoins > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||
			res->car == 'x' || res->car == 'X' || res->car == 'c' ||
			res->car == 's' || res->car == 'p' || res->car == '%')
		{
			if (i < res->stockmoins)
			{
				i = res->stockmoins - i;
				if (!(ret = ft_create_str_spaces(i)))
					return ;
				if (!(res->struc = ft_strfjoin_spaces(res->struc, ret, 3)))
					return ;
				if (!res->struc)
					return ;
			}
			res->stockmoins = 0;
		}
	}
}
