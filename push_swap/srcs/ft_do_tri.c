/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:23:42 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 16:22:20 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rr_or_r(t_swap **lst_a, t_tri *tri)
{
	t_swap	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (*lst_a);
	while (tri->nb_rank != tmp->rank)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		j++;
		tmp = tmp->next;
	}
	if (j < i)
		return (1);
	return (0);
}

int	ft_put_little(t_swap **lst_a, t_swap **lst_b)
{
	t_swap	*tmp;
	int		rank;

	tmp = (*lst_a);
	rank = (*lst_b)->rank;
	while (tmp != NULL)
	{
		if (rank > tmp->rank)
			rank = tmp->rank;
		tmp = tmp->next;
	}
	return (rank);
}

int	to_b_in_a(t_swap **lst_a, t_swap **lst_b)
{
	t_swap	*tmp;
	int		rank;
	int		comp;
	int		stock;

	comp = 0;
	rank = (*lst_b)->rank;
	tmp = (*lst_a);
	while (tmp != NULL)
	{
		if (tmp->rank > rank)
		{
			if (comp == 0 || comp < (rank - tmp->rank))
			{
				stock = tmp->rank;
				comp = rank - tmp->rank;
			}
		}
		tmp = tmp->next;
	}
	if (comp != 0)
		return (stock);
	comp = ft_put_little(lst_a, lst_b);
	return (comp);
}

void	ft_search_little_cut(t_swap **lst_a, t_tri *tri)
{
	t_swap	*tmp;

	tri->cmpt_i = 0;
	tri->cmpt_j = 0;
	tmp = (*lst_a)->next;
	while (tmp != NULL)
	{
		if (tri->nb_rank > tmp->rank)
			tri->nb_rank = tmp->rank;
		tmp = tmp->next;
	}
	tmp = (*lst_a);
	while (tmp->rank != tri->nb_rank)
	{
		tri->cmpt_i++;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		tri->cmpt_j++;
		tmp = tmp->next;
	}
}

int	ft_search_little(t_swap **lst_a, t_tri *tri)
{
	tri->nb_rank = (*lst_a)->rank;
	ft_search_little_cut(lst_a, tri);
	if (tri->cmpt_j < tri->cmpt_i)
		return (1);
	else
		return (0);
}
