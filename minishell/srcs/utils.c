/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:20:03 by agachet           #+#    #+#             */
/*   Updated: 2021/06/21 16:31:48 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *src, char *dst)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
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

void	ft_free_split(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

char	*ft_strjoin(char *s1, char *s2, int mode)
{
	char	*ret;
	int		i;
	int		y;

	y = 0;
	i = 0;
	i = (ft_strlen(s1) + ft_strlen(s2));
	if (!(ret = malloc(i + 1)))
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	y = 0;
	if (mode == 4)
		while (s2[y] != '=')
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

char	*ft_strfjoin(char *s1, char *s2, int mode)
{
	char	*ret;

	if (!(ret = ft_strjoin(s1, s2, mode)))
		return (0);
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (ret);
}
