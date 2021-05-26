/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:49:21 by agachet           #+#    #+#             */
/*   Updated: 2021/05/25 16:16:18 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_atoi
{
	int			i;
	int			j;
	int			neg;
	long int	res;
}				t_atoi;

typedef struct s_swap
{
	int				nb;
	int				rank;
	struct s_swap	*next;
}				t_swap;

typedef struct s_tri
{
	int	i;
	int	min;
	int	max;
	int	nb_rank;
	int	cmpt_i;
	int	cmpt_j;
}				t_tri;

void	ft_lstadd_back(t_swap **list, long int valeur, int rank);
int		ft_verif_double(t_swap **list);
void	ft_ranking(t_swap *lst_a, t_tri *tri);
int		ft_lstlen(t_swap **lst);
int		ft_verif_tri(t_swap **list);
void	ft_push(t_swap **src, t_swap **dst, int mode);
void	ft_lstadd_front(t_swap **list, int valeur, int rank);
void	ft_dellst_front(t_swap **list);
void	ft_reverse_rotate(t_swap **list, int mode);
void	ft_dellst_back(t_swap **list);
void	ft_rotate(t_swap **list, int mode);
void	ft_tri(t_swap **lst_a, t_swap **lst_b, t_tri *tri);
void	ft_swap(t_swap *list, int mode);
int		to_b_in_a(t_swap **lst_a, t_swap **lst_b);
int		ft_search_little(t_swap **lst_a, t_tri *tri);
int		ft_rr_or_r(t_swap **lst_a, t_tri *tri);
int		ft_put_little(t_swap **lst_a, t_swap **lst_b);
void	ft_tri_for_five(t_swap **lst_a, t_swap **lst_b);
void	ft_tri_cut(t_swap **lst_a, t_swap **lst_b, t_tri *tri);
int		ft_cut_atoi_a(char *str, t_atoi *atoi);
void	ft_ordre_fin(t_swap **lst_a, t_tri *tri);
int		ft_cut_atoi_b(char **str, t_atoi *atoi);
void	ft_lstclear(t_swap **list);

#endif
