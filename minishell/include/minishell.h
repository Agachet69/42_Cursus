/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:20:17 by agachet           #+#    #+#             */
/*   Updated: 2021/06/03 15:51:45 by agachet          ###   ########.fr       */
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

typedef struct	s_env
{
	char			*str;
	struct s_env	*next;
}				t_env;

typedef struct	s_export
{
	char			*str;
	struct s_export	*next;
}				t_export;


int     ft_strlen(char *str);
char	*ft_strcat(char *src, char *dst);
int     ft_strcmp(char *s1, char *s2);
char	*ft_search_env(char **env, char *str);
char	**ft_split(char *s, char c);
void	ft_echo(char *str);
void	ft_pwd(void);
void	ft_env(t_env **env);
void	ft_cd(char *str);
void	ft_free_split(char **tab);
char	*ft_strjoin(char *src, char *str2);
void	ft_list(char **envir, t_env **env);
void	ft_print_lst(t_env **env);
void	ft_export(char *str, t_env **env, t_env **exp);
void	ft_lstadd_back(t_env **env, char *str);
//int	ft_is_exist(char *old, char *new);

#endif
