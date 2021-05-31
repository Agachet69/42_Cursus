/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:20:17 by agachet           #+#    #+#             */
/*   Updated: 2021/05/31 19:15:39 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int	ft_strlen(char *str);
char	*ft_strcat(char *src, char *str2);
int	ft_strcmp(char *s1, char *s2);


#endif
