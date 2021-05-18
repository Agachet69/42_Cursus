/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:27 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 18:25:39 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ra_rra(t_swap **lst_a)
{
	t_swap	*tmp;
	int		i;

	i = 0;
	tmp = (*lst_a);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	i /= 2;
	tmp = (*lst_a);
	if (tmp->rank <= i)
		return (1);
	return (2);
}

void	ft_tri(t_swap **lst_a, t_swap **lst_b , t_tri *tri)
{
	t_swap *tmp;

	tmp = (*lst_a);
	while (tri->i != tmp->rank)
	{

		// if (ft_ra_rra(lst_a) == 2)
		// {

			write(1, "ra\n", 4);
			ft_rotate(lst_a);
		// }
		// else
		// {
		// 	write(1, "rra\n", 5);
		// 	ft_reverse_rotate(lst_a);
		// }
		tmp = (*lst_a);
	}
	write(1, "pa\n", 4);
	ft_push(lst_a, lst_b);
	tri->i++;
	if ((*lst_a)->next == NULL)
	{
		while ((*lst_b) != NULL)
		{
			write(1, "pa\n", 4);
			ft_push(lst_b, lst_a);
		}
	}
}

int	ft_allrank(t_swap *lst)
{
	t_swap *tmp;

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
	t_swap *tmp;
	t_swap *tmp2;

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

void	ft_ranking(t_swap *lst)
{
	t_swap	*tmp;
	t_swap	*tmp2;
	int		i;

	i = 0;
	tmp = lst;
	tmp2 = lst;
	while (ft_allrank(lst) == -1)
	{
		ft_put_rank(lst, i);
		i++;
	}
}
