/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:13:33 by agachet           #+#    #+#             */
/*   Updated: 2021/06/01 16:12:22 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp_env(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s2[i] == '\0')
		return (0);
	return (-1);
}

char	*ft_search_env(char **env, char *str)
{
	int i;
	char *str2;

	i = 0;
	while (env[i] != NULL && (ft_strcmp_env(env[i] ,str) == -1))
		i++;
	if (env[i] == NULL)
		return NULL;
	str2 = env[i];
	while (*str2 != '=')
		str2++;
	return (str2 + 1);
}
