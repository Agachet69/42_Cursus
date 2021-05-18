/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:28:43 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 17:52:37 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_swap *list)
{
	int tmp;

	if (list == NULL)
		return;
	if (list->next == NULL)
		return ;
	tmp = list->nb;
	list->nb = list->next->nb;
	list->next->nb = tmp;
}

void	ft_rotate(t_swap **list)
{
	if ((*list) == NULL)
		return;
	ft_lstadd_back(list, (*list)->nb, (*list)->rank);
	ft_dellst_front(list);
}

void	ft_reverse_rotate(t_swap **list)
{
	t_swap *tmp;

	if ((*list) == NULL)
		return;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	ft_lstadd_front(list, tmp->nb, tmp->rank);
	ft_dellst_back(list);
}

void	ft_push(t_swap **src, t_swap **dst)
{
	if ((*src) == NULL)
		return ;
	ft_lstadd_front(dst, (*src)->nb, (*src)->rank);
	ft_dellst_front(src);
}

void	print_list(t_swap *list)
{
	t_swap *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d->", tmp->nb);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
