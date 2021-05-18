/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:49:21 by agachet           #+#    #+#             */
/*   Updated: 2021/05/17 18:01:20 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_swap
{
	int		nb;
	int		rank;
	struct	s_swap *next;
}				t_swap;

typedef struct	s_tri
{
	int nb_a;
	int	last_a;
	int	next_a;
	int nb_b;
	int	last_b;
	int	next_b;
	int cpmt_nb;
	int rr_or_r;
	int rrr;
	int rrr_b;
	int i;
}				t_tri;


int		get_next_line(char **str);
void	ft_swap(t_swap *list);
void	ft_push(t_swap **list_in, t_swap **list_on);
void	ft_rotate(t_swap **list);
void	ft_reverse_rotate(t_swap **list);
void	ft_rrr(t_swap **lst_a, t_swap **lst_b);
void	ft_rr(t_swap **lst_a, t_swap **lst_b);
void	ft_ss(t_swap *lst_a, t_swap *lst_b);
void	print_list(t_swap *list);
void	ft_dellst_front(t_swap **list);
void	ft_dellst_back(t_swap **list);
void	ft_lstadd_back(t_swap **list, int valeur, int rank);
void	ft_lstadd_front(t_swap **list, int valeur, int rank);
int		ft_verif_double(t_swap **list);
void	ft_tri(t_swap **lst_a, t_swap **lst_b, t_tri *tri);
void	ft_do_tri_a(t_swap **lst_a, t_swap **lst_b, t_tri *tri);
void	ft_do_tri_b(t_swap **lst_a, t_swap **lst_b, t_tri *tri);
int		ft_verif_tri(t_swap **list);
void	ft_ranking(t_swap *lst_a);
void	ft_put_last_nb(t_swap **lst_a, t_swap **lst_b, t_tri *tri);


#endif
