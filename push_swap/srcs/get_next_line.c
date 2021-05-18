/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:39:31 by agachet           #+#    #+#             */
/*   Updated: 2021/05/11 15:14:32 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void gnl_part_two(char **str, int l, char c)
{
	int		i;
	char	*tmp;

	tmp = malloc(l);
	if (!(tmp))
	{
		free(*str);
		//return (NULL);
	}
	i = -1;
	while (++i < l - 2)
		tmp[i] = (*str)[i];
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(*str);
	*str = tmp;
}

int get_next_line(char **str)
{
	int		r;
	int		l;
	char	c;

	l = 1;
	r = 1;
	*str = malloc(l);
	if (!(*str))
		return (-1);
	*str[0] = 0;
	while (r && l++ && c != '\n')
	{
		r = read(0, &c, 1);
		gnl_part_two((str), l, c);
	}
	return (r);
}
