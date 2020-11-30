/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:07:52 by agachet           #+#    #+#             */
/*   Updated: 2020/11/30 14:54:43 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenv110(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*a;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlenv110(s1);
	y = ft_strlenv110(s2);
	if (!(a = malloc(sizeof(char) * (i + y) + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		a[i] = s2[y];
		i++;
		y++;
	}
	a[i] = '\0';
	return (a);
}
