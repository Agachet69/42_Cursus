/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:12:51 by agachet           #+#    #+#             */
/*   Updated: 2020/11/26 11:24:34 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	if ((char *)dst == NULL && (char *)src == NULL)
		return (0);
	i = 0;
	a = (char *)src;
	b = (char *)dst;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (b);
}
