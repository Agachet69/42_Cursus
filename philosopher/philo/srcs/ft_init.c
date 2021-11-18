/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:01:57 by agachet           #+#    #+#             */
/*   Updated: 2021/11/03 18:46:41 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	ft_init_struct_thread(t_thread *thread_strc, int i, t_philo *philo)
{
	if (i != philo->nb_philo - 1)
		pthread_mutex_init(&thread_strc[i].ma_f, NULL);
	if (i == 0)
	{
		pthread_mutex_init(&thread_strc[philo->nb_philo - 1].ma_f, NULL);
		thread_strc[i].voisin_f = &thread_strc[philo->nb_philo - 1].ma_f;
	}
	else
		thread_strc[i].voisin_f = &thread_strc[i - 1].ma_f;
	thread_strc[i].i = i;
	thread_strc[i].eat = 1;
	thread_strc[i].limit_eat = 0;
	thread_strc[i].time = 0;
	thread_strc[i].info = philo;
}

void	ft_init_struc(t_philo *philo)
{
	philo->i = 0;
	philo->nb_philo = 0;
	philo->t_die = 0;
	philo->t_eat = 0;
	philo->t_sleep = 0;
	philo->nb_eat = -1;
	philo->cmpt = -1;
	philo->bool_die = 0;
}
