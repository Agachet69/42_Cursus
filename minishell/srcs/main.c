/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:52 by agachet           #+#    #+#             */
/*   Updated: 2021/06/03 17:09:17 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_parsing(char *str, t_env **env, t_env **exp)
{
	if (ft_strcmp(str, "echo") == 0)
	{
		ft_echo(str);
		return (0);
	}
	else if (ft_strcmp(str, "cd") == 0)
	{
		ft_cd(str);
		return (0);
	}
	else if (ft_strcmp(str, "pwd") == 0)
	{
		ft_pwd();
		return (0);
	}
	else if (ft_strcmp(str, "export") == 0)
	{
		ft_export(str, env, exp);
		return (0);
	}
	else if (ft_strcmp(str, "unset") == 0)
		return (0);
	else if (ft_strcmp(str, "env") == 0)
	{
		ft_env(env);
		return (0);
	}
	else if (ft_strcmp(str, "exit") == 0)
		return (0);
	return (-1);
}

int	get_next_std(char **str)
{
	char c;
	char *tmp;
	int i;
	int l;

	l = 1;
	if (!(*str = malloc(l)))
		return (-1);
	while (read(0, &c, 1) && l++ && c != '\n')
	{
		if (!(tmp = malloc(l)))
		{
			free(*str);
			return (-1);
		}
		i = -1;
		while (++i < l -2)
			tmp[i] = (*str)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*str);
		(*str) = tmp;
	}
	return (0);
}

int	ft_exec(char *cmd, char **env)
{
	char	**tab;
	pid_t	pid;
	int		status;
	int		i;
	char	*tst;
	char	**test;

	i = 0;
	if (cmd == NULL)
		return  (-1);

	tst = ft_search_env(env, "PATH=");
	test = ft_split(tst, ':');
	tab = ft_split(cmd, ' ');
	//printf("%s\n", tst);
	while (test[i] != NULL)
	{
		test[i] = ft_strcat("/" , test[i]);
		tst = ft_strcat(tab[0], test[i]);
		status = 0;
		pid = fork();
		if (pid == -1)
			return (printf("ERREUR\n"));
		else if (pid == 0)
		{
		//	printf("%s\n", tst);
			if (access(tst ,F_OK) == 0)
				/*if (*/execve(tst, tab, env)/* == -1)*/;
				//perror("shell");
		}
		else
		 	wait(&status);
		i++;
	}
	i = -1;
	// while (tab[++i] != NULL)
	// 	free(tab[i]);
	// free(tab);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_env	*env_lst;
	t_env	*exp;

	(void)av;
	(void)ac;
	env_lst = NULL;

	ft_list(env, &env_lst);
	ft_list(env, &exp);

	write(1, "$> ", 3);
	while (1)
	{
		get_next_std(&str);

		if (ft_parsing(str, &env_lst, &exp) == -1)
			ft_exec(str, env);
		//	printf("command not found\n");
		write(1, "$> ", 3);
	}
	return (0);
}
