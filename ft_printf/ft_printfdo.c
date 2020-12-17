/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:37:33 by agachet           #+#    #+#             */
/*   Updated: 2020/12/17 17:58:09 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c, t_printf *res)
{
	unsigned char d;

	d = c;
	write(1, &d, 1);
	res->pourcent++;
	return (0);
}

void	ft_putunsignednbr_base(t_printf *res, unsigned int nbr, char *base)
{
	unsigned long int	compteur;
	char				n;
	unsigned long int	nb;

	nb = (unsigned long int)nbr;
	compteur = ft_strlen(base);
	if (res->struc == 0)
		res->struc = ft_checknbr(nbr, compteur, res); // a free
	if (res->putnbr_zero++ == 0)
		res->struc[res->compteur_putnbr] = '\0';
		res->compteur_putnbr--;
	n = base[(nb % compteur)];
	if (nb >= compteur)
	{
		res->struc[res->compteur_putnbr] = n;
		ft_putnbr_base(res, (nb / compteur), base);
	}
	if (nb <= compteur && (!(nb < 0)))
		res->struc[res->compteur_putnbr] = n;
}

void	ft_putstr_calloc(t_printf *res, char *str)
{
	int i;

	if (!str)
	{
		str = "(null)";
	}
	i = ft_strlen(str);
	res->struc = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (str[i])
	{
		res->struc[i] = str[i];
		i++;
	}
	res->struc[i] = '\0'; // a free
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
