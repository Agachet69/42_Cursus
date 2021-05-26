/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:27:31 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 16:19:28 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init(t_swap *lst, t_tri *tri)
{
	t_swap	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp->rank = -1;
		tmp = tmp->next;
	}
	tri->i = 0;
	tri->min = 0;
}

int	ft_atoi_b(char **av, t_swap **swap)
{
	t_atoi	atoib;

	atoib.i = 1;
	while (av[atoib.i] != NULL)
	{
		ft_cut_atoi_b(av, &atoib);
		atoib.res *= atoib.neg;
		if (atoib.res > 2147483647 || atoib.res < -2147483648)
			return (-1);
		ft_lstadd_back(swap, atoib.res, -1);
		if (av[atoib.i][atoib.j] != '\0' && (!(av[atoib.i][atoib.j] >= '0' && \
		av[atoib.i][atoib.j] <= '9')))
			return (-1);
		atoib.i++;
	}
	return (0);
}

int	ft_atoi_a(char *str, t_swap **swap)
{
	t_atoi	atoi;

	atoi.i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[atoi.i])
	{
		if (ft_cut_atoi_a(str, &atoi) == -1)
			return (-1);
		while (str[atoi.i] >= '0' && str[atoi.i] <= '9')
		{
			atoi.res = (atoi.res * 10) + (str[atoi.i] - 48);
			atoi.i++;
		}
		if (str[atoi.i] != ' ' && str[atoi.i] != '\0')
			return (-1);
		while (str[atoi.i] == ' ')
			atoi.i++;
		atoi.res *= atoi.neg;
		if (atoi.res > 2147483647 || atoi.res < -2147483648)
			return (-1);
		ft_lstadd_back(swap, atoi.res, -1);
	}
	return (0);
}

int	ft_check_av(int ac, char **av, t_swap **swap)
{
	if (ac == 2)
	{
		if (ft_atoi_a(av[1], swap) == -1)
		{
			ft_lstclear(swap);
			return (-1);
		}
	}
	else
	{
		if (ft_atoi_b(av, swap) == -1)
		{
			ft_lstclear(swap);
			return (-1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_swap	*swap_a;
	t_swap	*swap_b;
	t_tri	tri;

	swap_a = NULL;
	swap_b = NULL;
	ft_init(swap_a, &tri);
	if (ac < 2)
		return (0);
	if (ac >= 2)
		if (ft_check_av(ac, av, &swap_a) == -1)
			return (printf("Error\n"));
	if (ft_verif_double(&swap_a) == -1)
		return (printf("Error\n"));
	ft_ranking(swap_a, &tri);
	if (ft_lstlen(&swap_a) <= 5 && ft_lstlen(&swap_a) >= 2)
		ft_tri_for_five(&swap_a, &swap_b);
	while (ft_verif_tri(&swap_a) == -1 || swap_b != NULL)
		ft_tri(&swap_a, &swap_b, &tri);
	ft_lstclear(&swap_a);
	ft_lstclear(&swap_b);
	return (0);
}
