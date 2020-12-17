/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:47:44 by agachet           #+#    #+#             */
/*   Updated: 2020/12/16 17:07:56 by agachet          ###   ########lyon.fr   */
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

void	ft_putchar_calloc(t_printf *res, char c)
{
	res->struc = ft_calloc(2, sizeof(char));
	if (!res->struc)
		return ;
	res->struc[0] = c;
	res->struc[1] = '\0';  // a free
	//printf("%s\n", res->struc);
}
