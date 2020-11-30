/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:11:51 by agachet           #+#    #+#             */
/*   Updated: 2020/11/27 15:17:43 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	y;
	char			*dest;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (0);
	while (s[y])
	{
		dest[y] = (*f)(y, s[y]);
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
