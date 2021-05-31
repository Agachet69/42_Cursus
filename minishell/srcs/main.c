/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:52 by agachet           #+#    #+#             */
/*   Updated: 2021/05/31 14:36:48 by agachet          ###   ########lyon.fr   */
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

int	main(int ac, char **av, char **env)
{
	char *str;

	(void)env;
	(void)ac;
	write(1, "$> ", 3);
	if (execve(av[1], av, NULL) == -1)
			perror("shell");
	while (1)
	{
		get_next_std(&str);
		if (ft_parsing(str) == -1)
			printf("command not found\n");
		write(1, "$> ", 3);
	}
	return (0);
}
