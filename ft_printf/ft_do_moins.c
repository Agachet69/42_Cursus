/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_moins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:41:12 by agachet           #+#    #+#             */
/*   Updated: 2020/12/17 11:05:49 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_moins(t_printf *res)
{
	int		i;
	char	*ret;


	i = ft_strlen(res->struc);
	if (res->stockmoins > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X' || res->car == 'c' ||\
			res->car == 's' || res->car == 'p')
		{
			if (i < res->stockmoins)
			{
				i = res->stockmoins - i;
				ret = ft_create_str_spaces(i);
				res->struc = ft_strfjoin_spaces(res->struc, ret, 3);
			}
		}
	}
}
