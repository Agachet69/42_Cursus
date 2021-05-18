/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:23:42 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 14:05:14 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_rr_or_r(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	t_swap *tmp;

	tri->cpmt_nb = 0;
	tri->rr_or_r = 0;
	tmp = (*lst_a)->next;
	while (tmp != NULL)
	{
		if (tri->nb_a < tmp->nb)
			tri->rr_or_r++;
		tmp = tmp->next;
		tri->cpmt_nb++;
	}
	tmp = (*lst_b);
	while (tmp != NULL)
	{
		if (tri->nb_a < tmp->nb)
			tri->rr_or_r++;
		tmp = tmp->next;
		tri->cpmt_nb++;
	}
	if (tri->rr_or_r > (tri->cpmt_nb / 2))
		tri->rrr = 1;
	else
		tri->rrr = 0;
}

void	ft_check_rr_or_rb(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	t_swap *tmp;

	tri->cpmt_nb = 0;
	tri->rr_or_r = 0;
	tmp = (*lst_a);

	while (tmp != NULL)
	{
		if (tri->nb_b < tmp->nb)
			tri->rr_or_r++;
		tmp = tmp->next;
		tri->cpmt_nb++;
	}
	tmp = (*lst_b);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tri->nb_b > tmp->next->nb)
			tri->rr_or_r++;
		tmp = tmp->next;
		tri->cpmt_nb++;
	}

	if (tri->rr_or_r > (tri->cpmt_nb / 2))
		tri->rrr_b = 1;
	else
		tri->rrr_b = 0;
}

void	ft_put_last_nb(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	t_swap *tmp;

	tmp = (*lst_a);

	tri->nb_a = tmp->nb;
	tri->next_a = tmp->next->nb;
	while (tmp->next != NULL)
	tmp = tmp->next;
	tri->last_a = tmp->nb;
	if ((*lst_b) != NULL)
	{
		tmp = (*lst_b);
		tri->nb_b = tmp->nb;
		if ((*lst_b)->next != NULL)
		{
			tri->next_b = tmp->next->nb;
			while (tmp->next != NULL)
			tmp = tmp->next;
			tri->last_b = tmp->nb;
		}
	}
}

void	ft_do_tri_a(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	ft_put_last_nb(lst_a, lst_b, tri);
	if (tri->nb_a > tri->next_a && tri->nb_b < tri->next_b &&\
		(*lst_b) != NULL/* && (*lst_a) != NULL*/)
		ft_ss((*lst_a), (*lst_b));
	else if (tri->nb_a > tri->next_a)
	{
		write(1, "sa\n", 4);
		ft_swap(*lst_a);
	}
	else if (tri->nb_a > tri->last_a && tri->nb_b < tri->last_b &&\
			(*lst_b) != NULL)
		ft_rr(lst_a, lst_b);
	else if (tri->nb_a > tri->last_a)
	{
		write(1, "ra\n", 4);
		ft_rotate(lst_a);
	}
	else
	{
		write(1, "pb\n", 4);
		ft_push(lst_a, lst_b);
	}
}

void	ft_do_tri_b(t_swap **lst_a, t_swap **lst_b, t_tri *tri)
{
	ft_put_last_nb(lst_a, lst_b, tri);
	// ft_check_rr_or_r(lst_a, lst_b, tri);
	// ft_check_rr_or_rb(lst_a, lst_b, tri);
	if (tri->nb_a > tri->next_a && tri->nb_b < tri->next_b &&\
		(*lst_b) != NULL && (*lst_a) != NULL)
		ft_ss((*lst_a), (*lst_b));
	else if (tri->nb_b < tri->next_b)
	{
		write(1, "sb\n", 4);
		ft_swap(*lst_b);
	}
	else if (tri->nb_a > tri->last_a && tri->nb_b < tri->last_b &&\
		(*lst_b) != NULL && (*lst_b) != NULL)
		ft_rr(lst_a, lst_a);
	else if (tri->nb_b < tri->last_b)
	{
		write(1, "rb\n", 4);
		ft_rotate(lst_b);
	}
	else
	{
		write(1, "pa\n", 4);
		ft_push(lst_b, lst_a);
	}
}
