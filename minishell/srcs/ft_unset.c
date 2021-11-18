/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:46:57 by agachet           #+#    #+#             */
/*   Updated: 2021/06/07 19:09:16 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_del_maillon(t_env **env, int i)
{
	int		j;
	t_env	*tmp;

	j = 0;
	tmp = *env;
	if (i == 0)
	{
		*env = (*env)->next;
		return (tmp);
	}
	while (j < (i - 1))
	{
		tmp = tmp->next;
		j++;
	}
	if (tmp->next->next == NULL)
	{
		tmp->next = NULL;
		return (tmp);
	}
	tmp->next = tmp->next->next;
	return (tmp);
}

int	ft_seach_str(char *old, char *str)
{
	int	i;

	i = 0;
	while (old[i] && str[i])
	{
		if (str[i] != old[i])
			return (0);
		i++;
	}
	if (old[i] == '=' && str[i] == '\0')
		return (1);
	if (old[i] == '\0' && str[i] == '\0')
		return (1);
	return (0);
}

t_env	*ft_search_line(char *str, t_env **env)
{
	t_env	*tmp;
	t_env	*rez;
	int		i;

	i = 0;
	tmp = *env;
	while (tmp != NULL)
	{
		if (ft_seach_str(tmp->str, str) == 1)
		{
			rez = ft_del_maillon(env, i);
			return (tmp);
		}
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_unset(t_env **env, t_env **exp, char *str)
{
	char	**tab;
	int		i;
	t_env	*tmp;

	i = 1;
	tab = ft_split(str, ' ');
	while (tab[i] != NULL)
	{
		if (ft_search_line(tab[i], exp) != NULL)
			tmp = ft_search_line(tab[i], env);
		if (tmp != NULL)
		{
			free(tmp->str);
			free(tmp);
		}
		i++;
	}
}
