/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:10:51 by agachet           #+#    #+#             */
/*   Updated: 2020/12/17 18:54:53 by agachet          ###   ########lyon.fr   */
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
		ft_putunsignednbr_base(res, va_arg(ap, unsigned int), "0123456789");
	else if (res->car == 'x')
	{
		if (ft_base_hexa(res, va_arg(ap, int), "0123456789abcdef") == -1)
			return (-1);
	}
	else if (res->car == 'X')
	{
		if (ft_base_hexa(res, va_arg(ap, int), "0123456789ABCDEF") == -1)
			return (-1);
	}
	else if (res->car == 'p')
		ft_affadresse(res ,va_arg(ap, void*), "0123456789abcdef");
	return (0);
}

void	ft_check_flag(const char *str, t_printf *res)
{
	if (res->stockprecision >= 0)
 		ft_do_precision(res);
	if (res->stockstar > 0)
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
	res->car = str[res->i]; // met le char de la conversion 's' 'd' etc.. dqns la struct
	if (ft_checkstr(res, ap) == -1)
		return (-1); // l'envoie pour savoir la quelle c'est
	ft_check_flag(str, res); // agit en fonction des flags
	return (0);
}

void	ft_search_arg(const char *str, t_printf *res, va_list ap)
{
		if (str[res->i] == '*')
		{
			res->stockstar = va_arg(ap, int);
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
				res->stockprecision = va_arg(ap, int); // faire une fonction pour l'etoile.
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
	int			i;

	ft_initstruct(&res);
	va_start(ap, str);
	i = 0;
	while (str[res.i])
	{
		if (str[res.i] == '%')
		{
			if (ft_searchtype(str, &res, ap) == -1)
				return (-1);
			i = ft_strlen(res.struc) + i;
			ft_putstr(res.struc);
		}
		else
			i = write(1, &str[res.i], 1) + i;
		res.i++;
		ft_re_zero(&res);
	}
	va_end(ap);
	free(res.struc);
	// printf("%s\n", res.struc);
	return (i + res.pourcent);
}

int		main(void)
{
	char str[] = "bonjour";
	int i;
	int j;
	char a;
	a = 'b';
	i = 50;
	j = 15888779;
	j = printf("vrai = %-*.*d\n",15, 10 ,i);
	//printf("j = %d\n", j);
	j = ft_printf("moi  = %-*.*d\n",15, 10, i);
	//printf("j = %d\n", j);
	//printf("%d", i);
	return (0);
}
