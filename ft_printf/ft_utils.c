/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:26:16 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:42 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_boolean(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||\
			c == 'c' || c == 's' || c == 'p' || c == '%')
		return (1);
	else if ((c >= '0' && c <= '9') || (c == '*') || (c == '-') ||\
			(c == '.'))
		return (2);
	return (-1);
}

int		ft_boolean_bis(t_printf *res)
{
	if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X')
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
		if (res->stockzero < 0)
		{
			res->stockzero = res->stockzero * -1;
			res->stockmoins = res->stockzero;
			res->stockzero = 0;
		}
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
	if (str[res->i] == '*')
	{
		res->stockmoins = va_arg(ap, int);
		res->i++;
	}
	if (res->stockmoins < 0)
		res->stockmoins = res->stockmoins * -1;
	res->stockstar = 0;
}

void	ft_star_moins(t_printf *res)
{
	if (res->stockmoins == 0)
	{
		res->stockstar = res->stockstar * -1;
		res->stockmoins = res->stockstar;
		res->stockstar = 0;
	}
}
