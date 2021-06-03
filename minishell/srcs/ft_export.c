/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:44:39 by agachet           #+#    #+#             */
/*   Updated: 2021/06/03 17:09:32 by agachet          ###   ########.fr       */
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
		while (tmp->str[i] != '=')
		{
			write(1, &tmp->str[i], 1);
			i++;
		}
		write(1, &tmp->str[i], 1);
		i++;
		dprintf(1, "%c", b);
		while (tmp->str[i])
		{
			write(1, &tmp->str[i], 1);
			i++;
		}
		dprintf(1, "%c\n", b);
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

int	ft_expo_double(t_env **exp, char *str)
{
	int i;
	t_env *tmp;

	tmp = *exp;
	(void)str;

	i = 0;
	while (tmp != NULL)
	{
		if (ft_if_exist(tmp->str, str) == 1)
		{
			free(tmp->str);
			tmp->str = str;
			return (0);
		}
		if (ft_if_exist(tmp->str, str) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

void	ft_export(char *str, t_env **env, t_env **exp)
{
	char	**tab;
	int		i;
//	int		j;

	(void)env;
	i = 1;
	tab = ft_split(str, ' ');
	if (tab[1] == NULL)
		ft_print_exlst(exp);

	// else
	// {
	// 	while (tab[i] != NULL)
	// 	{
	// 		if (ft_expo_double(exp , tab[i]) == 0)
	// 			return ;
	// 		// j = 0;
	// 		// ft_lstadd_back(exp, tab[i]);
	// 		// while (tab[i][j])
	// 		// {
	// 		// 	if (tab[i][j] == '=')
	// 		// 	{
	// 		// 		if (ft() == -1)
	// 		// 		ft_lstadd_back(env, tab[i]);
	// 		// 	}
	// 		// 	j++;
	// 		// }
	// 		i++;
	// 	}
	// }
}
