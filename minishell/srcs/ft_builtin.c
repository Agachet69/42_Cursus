/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:28:11 by agachet           #+#    #+#             */
/*   Updated: 2021/06/21 16:19:23 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_aff_str(char *str)
{
	int	i;

	i = -1;
	while (str[i] != '=')
		i++;
	while (str[++i])
		write(1, &str[i], 1);
}

char	*ft_str_for_env(char *str, int i)
{
	int		j;
	int		nb;
	char	*str2;

	j = 0;
	i--;
	nb = i;
	while (str[++i] && str[i] != ' ')
		j++;
	str2 = malloc(j + 1);
	if (str == NULL)
		return (NULL);
	j = -1;
	while (str[++nb] && str[nb] != ' ')
		str2[++j] = str[nb];
	str2[++j] = '\0';
	return (str2);
}

int	ft_dollar(t_env **env, char *str, int i)
{
	t_env	*tmp;
	char	*str2;

	while (str[++i])
	{
		if (!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)))
		{
			write(1, "$", 1);
			write(1, &str[i], 1);
			return (i - 1);
		}
		else
		{
			str2 = ft_str_for_env(str, i);
			tmp = ft_search_str_in_env(env, str2);
			free(str2);
			if (tmp != NULL)
				ft_aff_str(tmp->str);
			while (str[i] && str[i] != ' ')
				i++;
			return (i - 1);
		}
	}
	return (i);
}

void	ft_echo_aff(char **tab, t_env **env)
{
	int	j;
	int i;

	j = 0;
	(void)env;
	while (tab[++j] != NULL)
	{
		i = -1;
		while (tab[j][++i])
		{
			if (tab[j][i] == '$')
			{
				if (tab[j][i + 1] != '@')
					i = ft_dollar(env, tab[j], i);
				else
					write(1, &tab[j][i], 1);
				i++;
			}
			else
				write(1, &tab[j][i], 1);
		}
		if (tab[j + 1] != NULL)
			write(1, " ", 1);
	}
}

int	ft_echo_n(char *str)
{
	int i;
	i = 2;
	if (str[0] == '-' && str[1] == 'n')
		while (str[i] && str[i] == 'n')
			i++;
	else
		return (1);
	if (str[i] == '\0')
		return (0);
	return (1);
}

char *ft_remplissage_str(char *str, int j, int i)
{
	char *str2;

	str2 = malloc(j + 1);
	if (str2 == NULL)
		return (NULL);
	j = -1;
	while (str[++i])
	{
		if (str[i] == 34)
			while (str[++i] && str[i] != 34)
				str2[++j] = str[i];
		else if (str[i] == 39)
			while (str[++i] != 39)
			{
				str2[++j] = str[i];
				//if (str[i] == '$')
				//	str2[++j] = '@';
			}
		else
		{
			//if (str[i] == '|')
			//	ft_pipe();
			str2[++j] = str[i];
		}
	}
	j++;
	str2[j] = '\0';
	free(str);
	return (str2);
}

int	ft_open_quote(char *str, int j, int i, int open)
{
	while (str[++i])
	{
		if (str[i] == 34)
		{
			open = 1;
			while (str[++i] && str[i] != 34)
				j++;
			if (str[i] == 34)
				open = 0;
		}
		else if (str[i] == 39)
		{
			open = 1;
			while (str[++i] && str[i] != 39)
				j++;
			if (str[i] == 39)
				open = 0;
		}
		else
			j++;
	}
	if (open == 1)
		return (-1);
	return (j);
}

char	*ft_remplissage(char *str)
{
	int i;
	int j;
	int	open;

	i = -1;
	open = 0;
	j = 0;
	j = ft_open_quote(str, j, i, open);
	if (j == -1)
		return (NULL);
	str = ft_remplissage_str(str, j, i);
	if (str == NULL)
		return (NULL);
	return (str);
}

void	ft_echo(char *str, t_env **env)
{
	char	**tab;
	int		i;

	i = 1;
	tab = ft_split(str, ' ');
	if (tab[1] == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	while (ft_echo_n(tab[i]) == 0)
			i++;
	ft_echo_aff(tab, env);
	if (i == 1)
		write(1, "\n", 1);
	return ;
	ft_free_split(tab);
}

void	ft_pwd(void)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	str = getcwd(str, i);
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

t_env	*ft_search_str_in_env(t_env **env, char *str)
{
	t_env	*tmp;
	int		i;

	tmp = *env;
	while (tmp != NULL)
	{
		i = -1;
		while (str[i] == tmp->str[i] || i == -1)
		{
			i++;
			if (str[i] == '\0')
			{
				return (tmp);
			}
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_cd(char *str, t_env **env)
{
	char	**tab;
	t_env	*tmp;
	t_env	*tmp2;
	char 	*str2;
	int		i;

	i = 0;
	str2 = NULL;
	tab = ft_split(str, ' ');
	if (tab[1] == NULL)
		chdir(getenv("HOME="));
	else
		chdir(tab[1]);
	ft_free_split(tab);
	str2 = getcwd(str2, i);
	tmp = ft_search_str_in_env(env, "OLDPWD=");
	tmp2 = ft_search_str_in_env(env, "PWD=");
	free(tmp->str);
	tmp->str = ft_strfjoin("OLDPWD", tmp2->str, 4);
	free(tmp2->str);
	tmp2->str = ft_strfjoin("PWD=", str2, 0);
}
