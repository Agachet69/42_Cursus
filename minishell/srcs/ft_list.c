/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:50:38 by agachet           #+#    #+#             */
/*   Updated: 2021/06/02 19:48:59 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstadd_back(t_env **env, char *str)
{
	t_env	*new;
	t_env	*tmp;

	if (!(new = malloc(sizeof(new))))
		exit (EXIT_FAILURE);
	if (*env == NULL)
	{
		new->str = str;
		new->next = NULL;
		(*env) = new;
	}
	else
	{
		new->str = str;
		new->next = NULL;
		tmp = (*env);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}


void	ft_list(char **envir, t_env **env)
{
	int i;

	i = -1;
	while (envir[++i] != NULL)
		ft_lstadd_back(env, envir[i]);
}

void	ft_print_lst(t_env **env)
{
	t_env *tmp;

	tmp = (*env);
	while (tmp != NULL)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}
