/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:28:11 by agachet           #+#    #+#             */
/*   Updated: 2021/06/03 16:55:31 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo_n(char **tab)
{
	int j;
	int i;

	i = 0;
	j = 2;
	while (tab[j] != NULL)
	{
		while (tab[j][i])
		{
			write(1, &tab[j][i], 1);
			i++;
		}
		j++;
		i = 0;
		if (tab[j] != NULL)
			write(1, " ", 1);
	}
}

void	ft_echo_not_n(char **tab)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (tab[j] != NULL)
	{
		while (tab[j][i])
		{
			write(1, &tab[j][i], 1);
			i++;
		}
		j++;
		i = 0;
		if (tab[j] != NULL)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	ft_echo(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	if (ft_strcmp(tab[1], "-n") == 0)
		ft_echo_n(tab);
	else
		ft_echo_not_n(tab);
	i = -1;
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

void	ft_env(t_env **env)
{
	ft_print_lst(env);
}

void	ft_cd(char *str)
{
	char **tab;

	tab = ft_split(str, ' ');
	if (tab[1] == NULL)
		chdir(getenv("HOME="));
	else
		chdir(tab[1]);
	ft_free_split(tab);
}

