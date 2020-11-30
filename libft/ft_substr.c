/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:42:23 by agachet           #+#    #+#             */
/*   Updated: 2020/11/30 15:00:13 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	size_t			i;
	unsigned int	stock;
	unsigned int	compare;

	if (!s)
		return (NULL);
	stock = start;
	compare = ft_strlen(s);
	i = -1;
	while (s[start] && ++i < len)
		start++;
	if (!(a = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	a[i] = '\0';
	if (compare < stock)
		return (a);
	while (s[stock] && (i < len))
		a[i++] = s[stock++];
	a[i] = '\0';
	return (a);
}
