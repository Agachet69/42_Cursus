/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:54:42 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 15:44:29 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_simple(t_swap **lst_a)
{
	int	po;
	int	ptw;
	int	pth;

	po = (*lst_a)->rank;
	ptw = (*lst_a)->next->rank;
	pth = (*lst_a)->next->next->rank;
	if (po > ptw && po > pth)
	{
		ft_rotate(lst_a, 1);
		if (ptw > pth)
			ft_swap(*lst_a, 1);
	}
	else if (po < ptw && po > pth)
		ft_reverse_rotate(lst_a, 1);
	else if (po > ptw && po < pth)
		ft_swap(*lst_a, 1);
	else if (po < ptw && ptw > pth)
	{
		ft_reverse_rotate(lst_a, 1);
		ft_swap(*lst_a, 1);
	}
}

void	ft_for_five(t_swap **lst_a, t_swap **lst_b)
{
	while (ft_lstlen(lst_b) != 2)
	{
		if ((*lst_a)->rank == 1 || (*lst_a)->rank == 2)
			ft_push(lst_a, lst_b, 2);
		else
			ft_rotate(lst_a, 1);
	}
	ft_simple(lst_a);
	ft_push(lst_b, lst_a, 1);
	ft_push(lst_b, lst_a, 1);
	if (ft_verif_tri(lst_a) == -1)
		ft_swap(*lst_a, 1);
}

void	ft_for_four(t_swap **lst_a, t_swap **lst_b)
{
	while (ft_lstlen(lst_b) != 1)
	{
		if ((*lst_a)->rank == 1)
			ft_push(lst_a, lst_b, 2);
		else
			ft_rotate(lst_a, 1);
	}
	ft_simple(lst_a);
	ft_push(lst_b, lst_a, 1);
}

void	ft_tri_for_five(t_swap **lst_a, t_swap **lst_b)
{
	if ((ft_lstlen(lst_a) == 2) && (ft_verif_tri(lst_a) == -1))
		ft_swap(*lst_a, 1);
	if (ft_lstlen(lst_a) == 3 && (ft_verif_tri(lst_a) == -1))
		ft_simple(lst_a);
	if (ft_lstlen(lst_a) == 4 && (ft_verif_tri(lst_a) == -1))
		ft_for_four(lst_a, lst_b);
	if (ft_lstlen(lst_a) == 5 && (ft_verif_tri(lst_a) == -1))
		ft_for_five(lst_a, lst_b);
}
