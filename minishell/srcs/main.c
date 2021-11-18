/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:52 by agachet           #+#    #+#             */
/*   Updated: 2021/06/29 15:06:52 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_parsing(char **str, t_env **env, t_env **exp)
{
	if ((*str)[0] == '\0')
		return (0);
	*str = ft_remplissage(*str);
	if (*str == NULL)
		return (-2);
	if (ft_strcmp(*str, "echo") == 0)
	{
		ft_echo(*str, env);
		return (0);
	}
	else if (ft_strcmp(*str, "cd") == 0)
	{
		ft_cd(*str, env);
		return (0);
	}
	else if (ft_strcmp(*str, "pwd") == 0)
	{
		ft_pwd();
		return (0);
	}
	else if (ft_strcmp(*str, "export") == 0)
	{
		ft_export(*str, env, exp);
		return (0);
	}
	else if (ft_strcmp(*str, "unset") == 0)
	{
		ft_unset(env, exp, *str);
		return (0);
	}
	else if (ft_strcmp(*str, "env") == 0)
	{
		ft_print_lst(env);
		return (0);
	}
	else if (ft_strcmp(*str, "exit") == 0)
	{
		return (-2);
	}
	return (-1);
}

char    *get_line()
{
    char *line;

    line = NULL;
    if (line)
    {
        free(line);
        line = NULL;
    }
    line = readline("Minishell> ");
    if (line)
        add_history(line);
    return (line);
}

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_env	*env_lst;
	t_env	*exp;
	int		retour;

	(void)av;
	(void)ac;
	env_lst = NULL;
	ft_list(env, &env_lst);
	ft_list(env, &exp);
	while (1)
	{
		str = get_line();
		retour = ft_parsing(&str, &env_lst, &exp);
		if (retour == -2)
		{
			return (0);
		}
		if (retour == -1)
			if (ft_exec(str, env) == -1)
				return (-1);
		free(str);
	}
	return (0);
}
