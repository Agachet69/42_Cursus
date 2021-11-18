/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:44:39 by agachet           #+#    #+#             */
/*   Updated: 2021/06/08 15:18:45 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_exlst(t_env **exp)
{
	t_env	*tmp;
	int		i;
	char	b;

	tmp = (*exp);
	b = 34;
	while (tmp != NULL)
	{
		i = 0;
		dprintf(1, "declare -x ");
		while (tmp->str[i] != '=' && tmp->str[i] != '\0')
			write(1, &tmp->str[i++], 1);
		if (tmp->str[i] == '\0')
			dprintf(1, "\n");
		else
		{
			write(1, &tmp->str[i++], 1);
			dprintf(1, "%c", b);
			while (tmp->str[i])
			{
				write(1, &tmp->str[i], 1);
				i++;
			}
			dprintf(1, "%c\n", b);
		}
		tmp = tmp->next;
	}
}

int	ft_if_exist(char *old, char *new)
{
	int i;

	i = 0;
	while (old[i] && new[i] && old[i] != '=' && new[i] != '=')
	{
		if (old[i] != new[i])
			return (-1);
		i++;
	}
	if ((old[i] == '=' && new[i] == '=') || (old[i] == '\0' && new[i] == '\0'))
		return (1);
	else if (old[i] == '\0' && new[i] == '=')
		return (1);
	else if (old[i] == '=' && new[i] == '\0')
		return (0);
	return (-1);
}

int	ft_(t_env **env, char *str, t_bool *freez)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		if (ft_if_exist(tmp->str, str) == 1)
		{
			if (freez->i == 0)
				free(tmp->str);
			tmp->str = str;
			freez->i = 1;
			return (0);
		}
		if (ft_if_exist(tmp->str, str) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_expo_double(t_env **exp, char *str, t_env **env)
{
	int		i;
	t_bool	freez;

	i = 0;
	freez.i = 0;
	if (ft_(exp, str, &freez) == -1)
		ft_lstadd_back(exp, str);
	if (ft_(env, str, &freez) == -1)
	{
		while (str[i])
		{
			if (str[i] == '=')
				ft_lstadd_back(env, str);
			i++;
		}
	}
	return (0);
}

char	*ft_cut_verif(char *str, char *new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 34)
			i++;
		else
		{
			new[j] = str[i];
			i++;
			j++;
		}
	}
	new[j] = '\0';
	return (new);
}

char	*ft_veriftab(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 34)
			j++;
		i++;
	}
	if (j == 0)
		return (str);
	if ((j % 2) != 0)
		return (NULL);
	new = malloc(ft_strlen(str) - j);
	if (new == NULL)
		return (NULL);
	new = ft_cut_verif(str,new);
	free(str);
	return (new);
}

void	ft_export(char *str, t_env **env, t_env **exp)
{
	char	**tab;
	int		i;

	(void)env;
	i = 1;
	tab = ft_split(str, ' ');
	if (tab[i] == NULL)
		ft_print_exlst(exp);
	else
	{
		while (tab[i] != NULL)
		{
			tab[i] = ft_veriftab(tab[i]);
			if (tab[i] == NULL)
				return ;
			ft_expo_double(exp , tab[i], env);
			i++;
		}
	}
}
