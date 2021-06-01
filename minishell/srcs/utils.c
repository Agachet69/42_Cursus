/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:20:03 by agachet           #+#    #+#             */
/*   Updated: 2021/06/01 17:32:48 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcat(char *src, char *str2)
{
	char *dst;
	int i;
	int j;

	j = 0;
	i = 0;
	dst = malloc(ft_strlen(src) + 6);
	while (str2[i])
	{
		dst[i] = str2[i];
		i++;
	}
	while(src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s2[i] == '\0' && (s1[i] == ' '))
		return (0);
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

int		ft_foundnb(char *s, char c)
{
	int	j;

	j = 1;
	while (*s != '\0' && *s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			j++;
		s++;
	}
	return (j);
}

char	*ft_copy(char *str, char c)
{
	int		j;
	char	*res;

	j = 0;
	while (str[j] && str[j] != c)
		j++;
	if (!(res = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = 0;
	while ((*str) && (*str) != c)
		res[j++] = (*str++);
	res[j] = '\0';
	return (res);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		j;
	int		nb;

	if (!str)
		return (NULL);
	nb = ft_foundnb(str, c);
	if (!(res = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	j = 0;
	while (j < nb)
	{
		while (*str == c && *str)
			str++;
		res[j] = ft_copy(str, c);
		if (j++ < nb)
			while (*str && *str != c)
				str++;
	}
	res[j] = NULL;
	return (res);
}
