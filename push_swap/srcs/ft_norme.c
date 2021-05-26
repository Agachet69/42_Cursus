/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:08:17 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 16:14:35 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_cut_atoi_a(char *str, t_atoi *atoi)
{
	atoi->res = 0;
	atoi->neg = 1;
	if (str[atoi->i] == '-')
	{
		atoi->neg = -1;
		atoi->i++;
		if (!(str[atoi->i] >= '0' && str[atoi->i] <= '9'))
			return (-1);
	}
	if (str[atoi->i] == ' ')
		return (-1);
	return (0);
}

int	ft_cut_atoi_b(char **str, t_atoi *atoi)
{
	atoi->j = 0;
	atoi->neg = 1;
	atoi->res = 0;
	if (str[atoi->i][atoi->j] == '-')
	{
		atoi->neg = -1;
		atoi->j++;
	}
	while (str[atoi->i][atoi->j] >= '0' && str[atoi->i][atoi->j] <= '9')
	{
		atoi->res = (atoi->res * 10) + (str[atoi->i][atoi->j] - 48);
		atoi->j++;
	}
	return (0);
}

void	ft_lstclear(t_swap **list)
{
	t_swap	*tmp;

	if (list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}
