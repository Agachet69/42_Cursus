/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:44:25 by agachet           #+#    #+#             */
/*   Updated: 2020/11/27 15:13:11 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charset(char const *set, char const s1)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlen112(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*chaine(int i, int y, char *str, char const *s1)
{
	int k;

	k = 0;
	while (i <= y)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	if (!s1)
		return (0);
	while (ft_charset(set, s1[i]) == 0)
		i++;
	y = ft_strlen112(s1) - 1;
	while ((y >= 0) && (ft_charset(set, s1[y]) == 0))
		y--;
	if (y <= i)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (0);
		str[0] = '\0';
		return (str);
	}
	else if (!(str = malloc(sizeof(char) * (y - i + 2))))
		return (0);
	str[0] = '\0';
	return (chaine(i, y, str, s1));
}
