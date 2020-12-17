/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:24:29 by agachet           #+#    #+#             */
/*   Updated: 2020/12/17 18:39:40 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_boolean(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||\
	 c == 'c' || c == 's')
			return (1);
	if ((c >= '0' && c <= '9') || (c == '*') || (c == '-') || (c = '.'))
		return (2);
	else
		return (-1);
}

int		ft_boolean_bis(t_printf *res)
{
	if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
		res->car == 'x' || res->car == 'X') // 'c' ?
			return (1);
	if (res->car == 's')
		return (0);
	return (-1);
}

void	ft_for_star_zero(va_list ap, t_printf *res, const char *str)
{
	if (str[res->i + 1] == '*')
	{
		res->stockzero = va_arg(ap, int);
		res->i += 2;
	}
	else
		res->stockzero = ft_atoi(str, res);
}

void	ft_for_star_moins(va_list ap, t_printf *res, const char *str)
{
	if (str[res->i + 1] == '*')
	{
		res->stockmoins = va_arg(ap, int);
		res->i += 2;
	}
	else
		res->stockmoins = ft_atoi(str, res);
}
