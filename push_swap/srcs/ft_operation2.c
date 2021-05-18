/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:10:05 by agachet           #+#    #+#             */
/*   Updated: 2021/05/15 14:17:26 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rrr(t_swap **lst_a, t_swap **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	write(1, "rrr\n", 5);
}

void	ft_rr(t_swap **lst_a, t_swap **lst_b)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	write(1, "rr\n", 4);
}

void	ft_ss(t_swap *lst_a, t_swap *lst_b)
{
	ft_swap(lst_a);
	ft_swap(lst_b);
	write(1, "ss\n", 4);
}
