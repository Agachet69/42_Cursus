/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:51:31 by agachet           #+#    #+#             */
/*   Updated: 2020/12/22 11:43:10 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *src)
{
	int i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_checknbr(int nbr, int compteur, t_printf *res)
{
	int			i;
	long int	nb;
	char		*dst;

	nb = nbr;
	i = 0;
	if (nb == 0 && i == 0)
		i = 1;
	if (nb < 0)
	{
		i++;
		nb = (nb * -1);
	}
	while (nbr != 0)
	{
		nbr = nbr / compteur;
		i++;
	}
	res->compteur_putnbr = i;
	dst = ft_calloc((i + 1), sizeof(char));
	return (dst);
}

void	ft_putnbr_base(t_printf *res, int nbr, char *base)
{
	int			compteur;
	char		n;
	long int	nb;

	nb = (long int)nbr;
	compteur = ft_strlen(base);
	if (res->struc == 0)
		res->struc = ft_checknbr(nbr, compteur, res);
	if (res->putnbr_zero++ == 0)
		res->struc[res->compteur_putnbr] = '\0';
	if (nb < 0)
	{
		res->struc[0] = '-';
		nb = nb * -1;
	}
	res->compteur_putnbr--;
	n = base[(nb % compteur)];
	if (nb >= compteur)
	{
		res->struc[res->compteur_putnbr] = n;
		ft_putnbr_base(res, (nb / compteur), base);
	}
	if (nb < compteur)
		res->struc[res->compteur_putnbr] = n;
}
