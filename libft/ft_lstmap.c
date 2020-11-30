/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:46:07 by agachet           #+#    #+#             */
/*   Updated: 2020/11/30 16:01:49 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *result;
    t_list *head;

    if (!lst)
        return (NULL);
    head = 0;
    while (lst)
    {    
        if (!(result = ft_lstnew((*f)(lst->content))))
        {
            ft_lstclear(&head, del);
            ft_lstclear(&result, del);
            return (NULL);
        }
            ft_lstadd_back(&head, result);
            lst = lst->next;
    }
    return (head);
} 