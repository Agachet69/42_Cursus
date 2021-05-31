/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:20:03 by agachet           #+#    #+#             */
/*   Updated: 2021/05/31 19:15:00 by agachet          ###   ########lyon.fr   */
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
