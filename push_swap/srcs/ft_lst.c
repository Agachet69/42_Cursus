/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:27:09 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 17:40:13 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_dellst_back(t_swap **list)
{
	t_swap	*tmp;
	t_swap	*ptmp;

	if (*list == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	tmp = *list;
	ptmp = *list;
	while (tmp->next != NULL)
	{
		ptmp = tmp;
		tmp = tmp->next;
	}
	ptmp->next = NULL;
	free(tmp);
}

void	ft_lstadd_back(t_swap **swap, int valeur, int rank)
{
	t_swap *new;
	t_swap *tmp;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(EXIT_FAILURE);
	if (*swap == NULL)
	{
		new->nb = valeur;
		new->rank = rank;
		new->next = NULL;
		*swap = new;
		return ;
	}
	else
	{
		new->nb = valeur;
		new->rank = rank;
		new->next = NULL;
		tmp = *swap;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_dellst_front(t_swap **list)
{
	t_swap	*tmp;


	if (list == NULL)
		return ;
	tmp = (*list)->next;

	free(*list);
	*list = tmp;

}

void	ft_lstadd_front(t_swap **list, int valeur, int rank)
{
	t_swap	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->nb = valeur;
	new->rank = rank;
	new->next = *list;
	*list = new;
}
