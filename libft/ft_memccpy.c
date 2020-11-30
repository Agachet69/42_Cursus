/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:34:20 by agachet           #+#    #+#             */
/*   Updated: 2020/11/26 10:55:01 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n > i)
	{
		(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
		if (((unsigned char *)src)[i] == ((unsigned char)c))
			return (dst + i + 1);
		i++;
	}
	return (0);
}
