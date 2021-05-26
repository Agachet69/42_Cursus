/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:27 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 15:46:13 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_allrank(t_swap *lst)
{
	t_swap	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->rank == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_put_rank(t_swap *lst, int i)
{
	t_swap	*tmp;
	t_swap	*tmp2;

	tmp = lst;
	tmp2 = lst;
	while (tmp->rank != -1)
		tmp = tmp->next;
	while (tmp2 != NULL)
	{
		if (tmp->nb > tmp2->nb && tmp2->rank == -1)
		{
			tmp = tmp2;
			tmp2 = lst;
		}
		else
			tmp2 = tmp2->next;
	}
	tmp->rank = i;
}

void	ft_ranking(t_swap *lst, t_tri *tri)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	int		i;

	i = 1;
	tmp = lst;
	tmp2 = lst;
	while (ft_allrank(lst) == -1)
	{
		ft_put_rank(lst, i);
		i++;
	}
	if (ft_lstlen(&lst) <= 250)
		tri->i = 25;
	else
		tri->i = (ft_lstlen(&lst) / 10);
	tri->max = 0;
}

void	ft_ordre_fin(t_swap **lst_a, t_tri *tri)
{
	if ((ft_search_little(lst_a, tri)) == 1)
		while ((*lst_a)->rank != tri->nb_rank)
			ft_reverse_rotate(lst_a, 1);
	else
		while ((*lst_a)->rank != tri->nb_rank)
			ft_rotate(lst_a, 1);
}

// void	ft_tri_cut(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
// {
// 	int	i;

// 	ft_push(lst_b, lst_a, 1);
// 	while ((*lst_b) != NULL)
// 	{
// 		tri->nb_rank = to_b_in_a(lst_a, lst_b);
// 		i = 0;
// 		if (ft_rr_or_r(lst_a, tri) == 1)
// 			while ((*lst_a)->rank != tri->nb_rank)
// 				ft_reverse_rotate(lst_a, 1);
// 		else
// 			while ((*lst_a)->rank != tri->nb_rank)
// 				ft_rotate(lst_a, 1);
// 		ft_push(lst_b, lst_a, 1);
// 	}
// 	ft_ordre_fin(lst_a, tri);
// }

void	ft_tri(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	t_swap	*tmp;
	int		taille;

	taille = ft_lstlen(lst_a);
	if (tri->i > taille)
		tri->max += taille;
	else
		tri->max += tri->i;
	while ((ft_lstlen(lst_b)) < (tri->max))
	{
		tmp = (*lst_a);
		if (tmp->rank > tri->min && tmp->rank <= tri->max)
			ft_push(lst_a, lst_b, 2);
		else
			ft_rotate(lst_a, 1);
	}
	tri->min += tri->i;
	if ((*lst_a) == NULL)
		ft_tri_cut(lst_a, lst_b, tri);
}
