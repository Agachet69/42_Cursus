/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:50:30 by agachet           #+#    #+#             */
/*   Updated: 2020/12/18 15:18:59 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

char	*ft_adresse_zero_x(void)
{
	char *str;

	str = ft_calloc(12, sizeof(char));
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

void	ft_p_negativ(t_printf *res)
{
	int i;

	i = 2;
	while (i < 10)
	{
		res->struc[i] = 'f';
		i++;
	}
}

void	ft_affadresse(t_printf *res, unsigned long chaine, char *base)
{
	char						str[9];
	int							i;
	int							j;

	res->struc = ft_adresse_zero_x();
	i = 8;
	while (((chaine / 16) > 0) || (i > 8))
	{
		str[i] = base[(chaine % 16)];
		chaine = chaine / 16;
		i--;
	}
	str[i] = base[(chaine % 16)];
	j = 2;
	while (i < 9)
	{
		res->struc[j] = str[i];
		i++;
		j++;
	}
	res->struc[j] = '\0'; // struc malloc donc a free;
	return ;
}
