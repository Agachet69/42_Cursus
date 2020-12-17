/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:03:37 by agachet           #+#    #+#             */
/*   Updated: 2020/12/16 18:07:55 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_checknbr_hexa(int nbr, int compteur, t_printf *res)
{
	int i;
	long int nb;
	char *dst;

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

int		ft_base_hexa(t_printf *res, int nbr, char *base)
{
	int			compteur;
	char		n;
	long int	nb;

	if (nbr < 0)
		return (-1); // return a gerer.
	nb = (long int)nbr;
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
	return (0);
}
