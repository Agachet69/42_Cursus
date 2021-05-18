/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:03:37 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 16:57:13 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_verif_double(t_swap **list)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = (*list)->next;
	tmp2 = (*list);
	while (tmp2->next != NULL)
	{
		tmp = tmp2->next;
		while (tmp != NULL)
		{
			if (tmp->nb == tmp2->nb)
			{
				//printf("double = %d", tmp->nb);
				//return (-1);
				tmp->nb *= 10;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int	ft_verif_tri(t_swap **list)
{
	t_swap	*tri;
	int		tmp;

	if ((*list) == NULL && (*list)->next == NULL)
		return (0);
	tri = (*list);
	while (tri->next != NULL)
	{
		tmp = tri->next->nb;
		if (tri->nb > tmp)
		{
			return (-1);
		}
		tri = tri->next;
	}
	return (0);
}

int	ft_verif_tri_b(t_swap **list)
{
	t_swap	*tri;
	int		tmp;

	if ((*list) == NULL && (*list)->next == NULL)
		return (0);
	tri = (*list);
	while (tri->next != NULL)
	{
		tmp = tri->next->nb;
		if (tri->nb < tmp)
			return (-1);
		tri = tri->next;
	}
	return (0);
}

