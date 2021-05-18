/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:10:51 by agachet           #+#    #+#             */
/*   Updated: 2020/12/22 16:49:30 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkstr(t_printf *res, va_list ap)
{
	if (res->car == 'c')
		ft_putchar_calloc(res, va_arg(ap, int));
	else if (res->car == 's')
		ft_putstr_calloc(res, va_arg(ap, char*));
	else if (res->car == 'd')
		ft_putnbr_base(res, va_arg(ap, int), "0123456789");
	else if (res->car == 'i')
		ft_putnbr_base(res, va_arg(ap, int), "0123456789");
	else if (res->car == 'u')
		ft_putun_base(res, va_arg(ap, unsigned int), "0123456789");
	else if (res->car == 'x')
		ft_putun_base(res, va_arg(ap, unsigned int), "0123456789abcdef");
	else if (res->car == 'X')
		ft_putun_base(res, va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (res->car == 'p')
		ft_affadresse(res, va_arg(ap, unsigned long), "0123456789abcdef");
	else if (res->car == '%')
		ft_putchar_calloc_pourcent(res);
	return (0);
}

void	ft_check_flag(t_printf *res)
{
	if (res->stockprecision >= 0)
		ft_do_precision(res);
	if (res->stockstar != 0)
		ft_do_star(res);
	if (res->stockzero > 0)
		ft_do_zero(res);
	if (res->stockmoins > 0)
		ft_do_moins(res);
	if (res->stockspaces > 0)
		ft_do_spaces(res);
}

int		ft_searchtype(const char *str, t_printf *res, va_list ap)
{
	res->i++;
	if (str[res->i] == '%')
		return (ft_putchar('%', res));
	while (ft_boolean(str[res->i]) != 1)
	{
		if (ft_boolean(str[res->i]) == (-1))
			return (-1);
		if (str[res->i] == '0')
			ft_for_star_zero(ap, res, str);
		ft_search_arg(str, res, ap);
	}
	res->car = str[res->i];
	if (ft_checkstr(res, ap) == -1)
		return (-1);
	ft_check_flag(res);
	if (!res->struc)
		return (-1);
	return (0);
}

void	ft_search_arg(const char *str, t_printf *res, va_list ap)
{
	if (str[res->i] == '*')
	{
		res->stockstar = va_arg(ap, int);
		if (res->stockstar < 0)
			ft_star_moins(res);
		res->i++;
	}
	if (str[res->i] == '-')
		ft_for_star_moins(ap, res, str);
	if (str[res->i] >= '0' || str[res->i] <= '9')
		res->stockspaces = ft_atoim(str, res);
	if (str[res->i] == '.')
	{
		if (str[res->i + 1] == '*')
		{
			res->stockprecision = va_arg(ap, int);
			res->i += 2;
		}
		else
			res->stockprecision = ft_atoi(str, res);
	}
	else
		return ;
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_printf	res;

	ft_initstruct(&res);
	va_start(ap, str);
	while (str[res.i])
	{
		if (str[res.i] == '%')
		{
			if (ft_searchtype(str, &res, ap) == -1)
				return (-1);
			res.ireturn = ft_strlen(res.struc) + res.ireturn;
			if (res.cas_zero_c != 1)
				ft_putstr(res.struc);
			free(res.struc);
		}
		else
			res.ireturn = write(1, &str[res.i], 1) + res.ireturn;
		res.i++;
		ft_re_zero(&res);
	}
	va_end(ap);
	free(res.struc);
	return (res.ireturn + res.pourcent);
}
