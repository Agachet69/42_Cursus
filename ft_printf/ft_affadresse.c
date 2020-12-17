/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:50:30 by agachet           #+#    #+#             */
/*   Updated: 2020/12/16 12:54:29 by agachet          ###   ########lyon.fr   */
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

void	ft_affadresse(t_printf *res, void *chaine, char *base)
{
	char						str[9];
	int							i;
	int							j;
	unsigned long long			tmp;

	res->struc = ft_adresse_zero_x();
	ft_bzero(str, 9);
	tmp = (unsigned long long)chaine;
	i = 8;
	while (((tmp /16) > 0) || (i >= 8))
	{
		str[i] = base[(tmp % 16)];
		tmp /= 16;
		i--;
	}
	str[i] = base[(tmp % 16)];
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
