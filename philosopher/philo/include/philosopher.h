/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:21:14 by agachet           #+#    #+#             */
/*   Updated: 2021/11/03 18:46:09 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				i;
	int				cmpt;
	int				nb_philo;
	int				bool_die;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	long int		nb_eat;
	long long int	start;
	long long		t;
}				t_philo;

typedef struct s_thread
{
	int				i;
	int				die;
	int				eat;
	long int		limit_eat;
	long long		time;
	pthread_mutex_t	ma_f;
	pthread_mutex_t	*voisin_f;
	t_philo			*info;
}				t_thread;

void	ft_init_struct_thread(t_thread *thread_strc, int i, t_philo *philo);
void	ft_init_struc(t_philo *philo);
void	ft_do_eat(t_thread *philo);
void	ft_do_sleep(t_thread *philo);
void	ft_do_think(t_thread *philo);
int		ft_die(t_thread *philo);

#endif
