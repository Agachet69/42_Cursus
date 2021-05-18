/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:53:10 by agachet           #+#    #+#             */
/*   Updated: 2020/12/22 15:50:11 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_star(t_printf *res)
{
	int		i;
	char	*ret;

	i = ft_strlen(res->struc);
	if (res->stockstar > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X' || res->car == 'c' ||\
			res->car == 's' || res->car == 'p')
		{
			if (i < res->stockstar)
			{
				i = res->stockstar - i;
				if (!(ret = ft_create_str_spaces(i)))
					return ;
				if (!(res->struc = ft_strfjoin_spaces(ret, res->struc, 3)))
					return ;
				if (!res->struc)
					return ;
			}
		}
		res->stockstar = 0;
	}
}
