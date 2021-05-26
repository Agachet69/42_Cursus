/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:17:58 by agachet           #+#    #+#             */
/*   Updated: 2021/05/26 18:28:21 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str, t_printf *res)
{
	int	result;

	result = 0;
	res->i++;
	while (str[res->i] >= '0' && str[res->i] <= '9')
	{
		result = (result * 10) + (str[res->i] - 48);
		res->i++;
	}
	return (result);
}

char	*ft_cz(int i, t_printf *res)
{
	int		j;
	int		k;
	char	*ret;

	if (!(ret = ft_calloc((i + 2), sizeof(char))))
		return (0);
	j = 0;
	k = 0;
	if (res->struc[j] == '-')
	{
		ret[k] = '-';
		k = 1;
	}
	while (i > j)
	{
		ret[k++] = '0';
		j++;
	}
	ret[k] = '\0';
	return (ret);
}

char	*ft_strjoin_zero(char *s1, char *s2)
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
	if (s2[0] == '-')
		y++;
	while (s2[y])
	{
		ret[i] = s2[y];
		i++;
		y++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strfjoinz(char *s1, char *s2, int mode)
{
	char	*ret;

	if (!(ret = ft_strjoin_zero(s1, s2)))
		return (0);
	if (!ret)
		return (0);
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (ret);
}

void	ft_do_zero(t_printf *res)
{
	int		i;
	char	*ret;

	i = ft_strlen(res->struc);
	if (res->stockzero > 0)
	{
		if (res->car == 'd' || res->car == 'i' || res->car == 'u' ||\
			res->car == 'x' || res->car == 'X' || res->car == 'c' ||\
			res->car == '%')
		{
			if (i < res->stockzero)
			{
				i = res->stockzero - i;
				if (!(ret = ft_cz(i, res)))
					return ;
				if (!(res->struc = ft_strfjoinz(ret, res->struc, 3)))
					return ;
			}
		}
	}
}
