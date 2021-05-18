/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:27:31 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 18:20:08 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init(t_swap *lst, t_tri *tri)
{
	t_swap *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp->rank = -1;
		tmp = tmp->next;
	}
	tri->i = 0;
}

int ft_atoi_b(char **av, t_swap **swap)
{
	int i;
	int j;
	int neg;
	int result;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		neg = 1;
		result = 0;
		if (av[i][j] == '-')
		{
			neg = -1;
			j++;
		}
		while (av[i][j] >= '0' && av[i][j] <= '9')
		{
			result = (result * 10) + (av[i][j] - 48);
			j++;
		}
		result *= neg;
		ft_lstadd_back(swap, result, -1);
		if (av[i][j] != '\0' && (!(av[i][j] >= '0' && av[i][j] <= '9')))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi_a(char *str, t_swap **swap)
{
	int i;
	int neg;
	int result;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		result = 0;
		neg = 1;
		if (str[i] == '-')
		{
			neg = -1;
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (-1);
		}
		if (str[i] == ' ')
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - 48);
			i++;
		}
		if (str[i] != ' ' && str[i] != '\0')
			return(-1);
		while (str[i] == ' ')
				i++;
		result *= neg;
		ft_lstadd_back(swap, result, -1);
	}
	return (0);
}

int	ft_check_av(int ac, char **av, t_swap **swap)
{
	if (ac == 2)
	{
		if (ft_atoi_a(av[1], swap) == -1)
			return(-1);
	}
	else
		if (ft_atoi_b(av, swap) == -1)
			return (-1);
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
	ft_ranking(swap_a);
	while (ft_verif_tri(&swap_a) == -1 || swap_b != NULL)
		ft_tri(&swap_a, &swap_b, &tri);
	print_list(swap_a);
	// while (get_next_line(&str))
	//printf("%d\n", ());
	return (0);
}
