/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:57:42 by agachet           #+#    #+#             */
/*   Updated: 2022/01/25 18:06:21 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static long	long	ft_get_time(long long int start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start);
}

int	ft_calcul_dead(t_thread *p)
{
	p->info->t = (ft_get_time(p->info->start) - p->time);
	if (p->info->nb_philo == 1)
	{
		usleep((p->info->t_die - p->info->t) * 1000);
		printf("%lldms n°%d died\n", ft_get_time(p->info->start), p->i);
		exit (0);
	}
	if (p->eat == 0 && (p->info->t + p->info->t_eat) > p->info->t_die)
	{
		if (p->info->bool_die == 1)
			return (1);
		p->info->bool_die = 1;
		usleep((p->info->t_die - p->info->t) * 1000);
		printf("%lldms n°%d died\n", ft_get_time(p->info->start), p->i);
		return (1);
	}
	else if (p->eat == 1 && \
	 (p->info->t + p->info->t_sleep) > p->info->t_die)
	{
		p->info->bool_die = 1;
		usleep((p->info->t_die - p->info->t) * 1000);
		printf("%lldms n°%d died\n", ft_get_time(p->info->start), p->i);
		return (1);
	}
	return (0);
}

void	ft_do_eat(t_thread *p)
{
	p->eat = 0;
	if (p->info->nb_philo == 1)
		ft_calcul_dead(p);
	pthread_mutex_lock(p->voisin_f);
	pthread_mutex_lock(&p->ma_f);
	if (ft_die(p) == 1)
	{
		pthread_mutex_unlock(p->voisin_f);
		pthread_mutex_unlock(&p->ma_f);
		return ;
	}
	printf("%lldms n°%d has taken a fork\n", ft_get_time(p->info->start), p->i);
	printf("%lldms n°%d is eating\n", ft_get_time(p->info->start), p->i);
	if (ft_calcul_dead(p) == 1)
	{
		pthread_mutex_unlock(p->voisin_f);
		pthread_mutex_unlock(&p->ma_f);
		return ;
	}
	usleep((p->info->t_eat * 1000));
	pthread_mutex_unlock(p->voisin_f);
	pthread_mutex_unlock(&p->ma_f);
	p->limit_eat++;
	p->eat = 1;
	p->time = ft_get_time(p->info->start);
}

void	ft_do_sleep(t_thread *philo)
{
	printf("%lldms n°%d is sleeping\n", \
	ft_get_time(philo->info->start), philo->i);
	if (ft_calcul_dead(philo) == 1)
		return ;
	usleep(philo->info->t_sleep * 1000);
	if (philo->info->bool_die == 1)
		return ;
	printf("%lldms n°%d is thinking\n", \
	ft_get_time(philo->info->start), philo->i);
}

int	ft_die(t_thread *philo)
{
	if ((ft_get_time(philo->info->start) - philo->time) > philo->info->t_die)
	{
		if (philo->info->bool_die != 1)
		{
			philo->info->bool_die = 1;
			printf("%lldms n°%d died\n", \
			ft_get_time(philo->info->start), philo->i);
			return (1);
		}
	}
	if (philo->info->bool_die == 1)
		return (1);
	return (0);
}
