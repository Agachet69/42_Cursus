/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:37:33 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:34 by agachet          ###   ########lyon.fr   */
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

char	*ft_ck_uns(unsigned long int nbr, int compteur, t_printf *res)
{
	int		i;
	char	*dst;

	i = 0;
	if (nbr == 0 && i == 0)
		i = 1;
	while (nbr != 0)
	{
		nbr = nbr / compteur;
		i++;
	}
	res->compteur_putnbr = i;
	if (!(dst = ft_calloc((i + 1), sizeof(char))))
		return (0);
	return (dst);
}

void	ft_putun_base(t_printf *res, unsigned long int nbr, char *base)
{
	unsigned long int	compteur;
	char				n;

	compteur = ft_strlen(base);
	if (res->struc == 0)
		res->struc = ft_ck_uns(nbr, compteur, res);
	if (res->putnbr_zero++ == 0)
		res->struc[res->compteur_putnbr] = '\0';
	res->compteur_putnbr--;
	n = base[(nbr % compteur)];
	if (nbr >= compteur)
	{
		res->struc[res->compteur_putnbr] = n;
		ft_putnbr_base(res, (nbr / compteur), base);
	}
	if (nbr < compteur)
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
	if (!(res->struc = ft_calloc((i + 1), sizeof(char))))
		return ;
	i = 0;
	while (str[i])
	{
		res->struc[i] = str[i];
		i++;
	}
	res->struc[i] = '\0';
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
