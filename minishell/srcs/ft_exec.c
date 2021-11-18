/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:08:18 by agachet           #+#    #+#             */
/*   Updated: 2021/06/21 16:16:12 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free_one(char **path, int i)
{
	while (path[++i] != NULL)
		free(path[i]);
	free(path);
}

char	**ft_valid(char **tst, char *cmd, char **env)
{
	char	**tab;
	char	**path;
	int		i;

	i = 0;
	*tst = ft_search_env(env, "PATH=");

	path = ft_split(*tst, ':');
	tab = ft_split(cmd, ' ');
	//printf("%s\n", cmd);

	while (path[i] != NULL)
	{
		path[i] = ft_strcat("/", path[i]);
		*tst = ft_strfjoin(path[i], tab[0], 1);
		if (access(*tst, F_OK) == 0)
		{
			ft_free_one(path, i);
			return (tab);
		}
		i++;
		free(*tst);
	}
	free(path);
	return (NULL);
}

int	ft_do_cmd(char *tst, char **tab, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		execve(tst, tab, env);
	else
		wait(&status);
	return (0);
}

int	ft_exec(char *cmd, char **env)
{
	char	*tst;
	char	**tab;
	int		i;
	int		crash;

	crash = 0;
	if (cmd == NULL)
		return (0);
	i = -1;
	tab = ft_valid(&tst, cmd, env);
	if (tab == NULL)
	{
		printf("minishell: %s: command not found\n", (cmd));
		return (0);
	}
	crash = ft_do_cmd(tst, tab, env);
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
	free(tst);
	if (crash == -1)
		return (-1);
	return (0);
}
