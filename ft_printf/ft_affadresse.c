/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:50:30 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:01 by agachet          ###   ########lyon.fr   */
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

char	*ft_adresse_zero_x(int k)
{
	char	*str;

	if (!(str = ft_calloc(k + 3, sizeof(char))))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int		ft_compteur_taille(unsigned long chaine)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (chaine != 0)
	{
		chaine = chaine / 16;
		i++;
		k++;
	}
	if (k == 0 && chaine == 0)
		i = 1;
	while (i < 9)
		i++;
	i = i + 1;
	return (i);
}

void	ft_affadresse(t_printf *res, unsigned long chaine, char *base)
{
	int		k;
	char	*str;
	int		i;

	k = ft_compteur_taille(chaine);
	if (!(str = ft_calloc(k, sizeof(char))))
		return ;
	k = 0;
	while (chaine != 0 || k == 0)
	{
		str[k++] = base[(chaine % 16)];
		chaine = chaine / 16;
	}
	str[k] = '\0';
	if (!(res->struc = ft_adresse_zero_x(k)))
		return ;
	i = 2;
	k--;
	while (k >= 0)
		res->struc[i++] = str[k--];
	res->struc[i] = '\0';
	free(str);
}
