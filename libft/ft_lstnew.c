/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:45:50 by agachet           #+#    #+#             */
/*   Updated: 2021/02/24 10:47:24 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *i;

	if (!(i = malloc(sizeof(t_list))))
		return (NULL);
	i->content = content;
	i->next = NULL;
	return (i);
}
