/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:00:16 by agachet           #+#    #+#             */
/*   Updated: 2020/12/21 14:19:45 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoim(const char *str, t_printf *res)
{
	int	result;

	result = 0;
	while (str[res->i] >= '0' && str[res->i] <= '9')
	{
		result = (result * 10) + (str[res->i] - 48);
		res->i++;
	}
	return (result);
}

char	*ft_create_str_spaces(int i)
{
	int		j;
	char	*ret;

	ret = ft_calloc((i + 1), sizeof(char));
	j = 0;
	while (i > j)
	{
		ret[j] = ' ';
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoin_spaces(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		y;

	y = 0;
	i = 0;
	i = (ft_strlen(s1) + ft_strlen(s2));
	if (!(ret = ft_calloc((i + 1), sizeof(char))))
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	y = 0;
	while (s2[y])
	{
		ret[i] = s2[y];
		i++;
		y++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strfjoin_spaces(char *s1, char *s2, int mode)
{
	char	*ret;

	ret = ft_strjoin_spaces(s1, s2);
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (ret);
}

void	ft_do_spaces(t_printf *res)
{
	int		i;
	char	*ret;


	i = ft_strlen(res->struc);
	i = i + res->cas_zero_c;
	if (res->stockspaces > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X' || res->car == 'c' ||\
			res->car == 's' || res->car == 'p')
		{
			if (i < res->stockspaces)
			{
				i = res->stockspaces - i;
				ret = ft_create_str_spaces(i);
				res->struc = ft_strfjoin_spaces(ret, res->struc, 3);
			}
		}
		res->stockspaces = 0;
	}
}
