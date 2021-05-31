/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:52 by agachet           #+#    #+#             */
/*   Updated: 2021/05/31 19:17:49 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_parsing(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (0);
	else if (ft_strcmp(str, "cd") == 0)
		return (0);
	else if (ft_strcmp(str, "pwd") == 0)
		return (0);
	else if (ft_strcmp(str, "export") == 0)
		return (0);
	else if (ft_strcmp(str, "unset") == 0)
		return (0);
	else if (ft_strcmp(str, "env") == 0)
		return (0);
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
	char	*str2 = "/bin/";

	tab = malloc(sizeof(1));
	//cmd	= ft_strcat(cmd, str2);
	tab[0] = ft_strcat(cmd, str2);
	status = 0;
	pid = fork();
	if (pid == -1)
		return (printf("ERREUR\n"));
	if (pid == 0)
	{
	if (execve(tab[0], tab, env) == -1)
		perror("shell");
	}
	else
	 	wait(&status);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*str;

	// char	**c_str;
	// pid_t	pid;
	// int		status;

	(void)env;
	(void)av;
	(void)ac;
	// c_str = NULL;
	// c_str = malloc(sizeof(char *)* 2);
	// get_next_std(&str);
	// c_str[0] = str;
	// c_str[1] = NULL;
	//printf("o\n");

	// status = 0;
	// pid = fork();
	// if (pid == -1)
	// 	return (printf("ERREUR\n"));
	// if (pid == 0)
	// {
	// 	if (execve(str, c_str, env) == -1)
	// 		perror("shell");
	// }
	// else
	// 	wait(&status);

	write(1, "$> ", 3);
	while (1)
	{
		get_next_std(&str);
		ft_exec(str, env);
		if (ft_parsing(str) == -1)
		//	printf("command not found\n");
		write(1, "$> ", 3);
	}
	return (0);
}
