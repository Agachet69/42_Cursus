/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:28:43 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 15:46:22 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_swap *list, int mode)
{
	int	tmp;
	int	tmp_rank;

	if (list == NULL)
		return ;
	if (list->next == NULL)
		return ;
	tmp_rank = list->rank;
	tmp = list->nb;
	list->nb = list->next->nb;
	list->rank = list->next->rank;
	list->next->rank = tmp_rank;
	list->next->nb = tmp;
	if (mode == 1)
		write(1, "sa\n", 3);
	if (mode == 2)
		write(1, "sb\n", 3);
}

void	ft_rotate(t_swap **list, int mode)
{
	if ((*list) == NULL)
		return ;
	if (mode == 1)
		write(1, "ra\n", 3);
	if (mode == 2)
		write(1, "rb\n", 3);
	ft_lstadd_back(list, (*list)->nb, (*list)->rank);
	ft_dellst_front(list);
}

void	ft_reverse_rotate(t_swap **list, int mode)
{
	t_swap	*tmp;

	if ((*list) == NULL)
		return ;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (mode == 1)
		write(1, "rra\n", 4);
	if (mode == 2)
		write(1, "rrb\n", 4);
	ft_lstadd_front(list, tmp->nb, tmp->rank);
	ft_dellst_back(list);
}

void	ft_push(t_swap **src, t_swap **dst, int mode)
{
	if ((*src) == NULL)
		return ;
	if (mode == 1)
		write(1, "pa\n", 3);
	if (mode == 2)
		write(1, "pb\n", 3);
	ft_lstadd_front(dst, (*src)->nb, (*src)->rank);
	ft_dellst_front(src);
}

void	ft_tri_cut(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	int	i;

	ft_push(lst_b, lst_a, 1);
	while ((*lst_b) != NULL)
	{
		tri->nb_rank = to_b_in_a(lst_a, lst_b);
		i = 0;
		if (ft_rr_or_r(lst_a, tri) == 1)
			while ((*lst_a)->rank != tri->nb_rank)
				ft_reverse_rotate(lst_a, 1);
		else
			while ((*lst_a)->rank != tri->nb_rank)
				ft_rotate(lst_a, 1);
		ft_push(lst_b, lst_a, 1);
	}
	ft_ordre_fin(lst_a, tri);
}
