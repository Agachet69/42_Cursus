/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:47:44 by agachet           #+#    #+#             */
/*   Updated: 2020/12/21 14:07:58 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (count * size))))
		return (0);
	ft_bzero(str, (count * size));
	return (str);
}

void	ft_cas_zero_c(t_printf *res)
{
	int i;

	i = 0;
	res->cas_zero_c = 1;
	if (res->stockspaces > 0 || res->stockstar > 0)
	{
		ft_do_spaces(res);
		ft_putstr(res->struc); // peu etre un leak
		write(1, &i, 1);
		res->stockspaces = 0;
	}
	else if (res->stockmoins > 0)
	{
		write(1, &i, 1);
		ft_do_moins(res);
		ft_putstr(res->struc);
		res->stockmoins = 0;
	}
	else
		write(1, &i, 1);
	res->cas_zero_c = 1;
	res->ireturn = res->cas_zero_c + res->ireturn;
}

void	ft_putchar_calloc(t_printf *res, char c)
{
	res->struc = ft_calloc(2, sizeof(char));
	if (!res->struc)
		return ;
	res->struc[0] = c;
	res->struc[1] = '\0';  // a free
	if (c == 0)
	{
		ft_cas_zero_c(res);
		return ;
	}
	//printf("%s\n", res->struc);
}
