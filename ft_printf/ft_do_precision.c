/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:13:28 by agachet           #+#    #+#             */
/*   Updated: 2020/12/22 16:07:05 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char *s, int i)
{
	char			*ret;
	int				compteur;

	compteur = 0;
	if (!s)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * i + 1)))
		return (0);
	while (i > compteur)
	{
		ret[compteur] = s[compteur];
		compteur++;
	}
	ret[compteur] = '\0';
	free(s);
	return (ret);
}

char	*ft_chaine_vide(t_printf *res)
{
	char *ret;

	if (!(ret = ft_calloc(1, sizeof(char))))
		return (0);
	ret[0] = '\0';
	free(res->struc);
	return (ret);
}

int		ft_specials(t_printf *res)
{
	if (res->stockprecision == 0)
	{
		if (res->struc[0] == '0' && (res->car == 'd' || res->car == 'i' ||\
		res->car == 'u' || res->car == 'x' || res->car == 'X'))
		{
			if (!(res->struc = ft_chaine_vide(res)))
				return (0);
			return (0);
		}
		else if (res->car == 's')
		{
			if (!(res->struc = ft_chaine_vide(res)))
				return (0);
			return (0);
		}
	}
	return (1);
}

void	ft_multy_flags(t_printf *res)
{
	if ((res->stockspaces > 0) && ft_boolean_bis(res) == 1)
	{
		ft_do_spaces(res);
		res->stockspaces = 0;
	}
	if ((res->stockzero > 0) && ft_boolean_bis(res) == 1)
	{
		res->stockspaces = res->stockzero;
		ft_do_spaces(res);
		res->stockzero = 0;
		res->stockspaces = 0;
	}
	if ((res->stockmoins > 0) && ft_boolean_bis(res) == 1)
	{
		ft_do_moins(res);
		res->stockmoins = 0;
	}
}

void	ft_do_precision(t_printf *res)
{
	int		i;

	ft_specials(res);
	i = ft_strlen(res->struc);
	if (res->stockprecision > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X')
		{
			if (res->struc[0] == '-')
				i--;
			if (i < res->stockprecision)
			{
				i = res->stockprecision - i;
				if (!(res->struc = ft_strfjoinz(ft_cz(i, res), res->struc, 3)))
					return ;
			}
		}
		else if (res->car == 's' && (res->stockprecision < i))
			if (!(res->struc = ft_substr(res->struc, res->stockprecision)))
				return ;
	}
	ft_multy_flags(res);
	res->stockprecision = 0;
}
