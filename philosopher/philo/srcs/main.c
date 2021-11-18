/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:55:51 by agachet           #+#    #+#             */
/*   Updated: 2021/11/03 18:37:28 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	ft_atoi(char *str, int nb, t_philo *philo)
{
	long int	res;
	int			i;

	i = 0;
	res = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (((!(str[i] <= '9' && str[i] >= '0')) && (str[i] != 0)) || res == 0)
		return (-1);
	if (res >= 4294967296)
		return (-1);
	if (nb == 1)
		philo->nb_philo = res;
	else if (nb == 2)
		philo->t_die = res;
	else if (nb == 3)
		philo->t_eat = res;
	else if (nb == 4)
		philo->t_sleep = res;
	else if (nb == 5)
		philo->nb_eat = res;
	return (0);
}

int	ft_parsing(char **av, int ac, t_philo *philo)
{
	int	i;

	i = 1;
	while (ac > i)
	{
		if (ft_atoi(av[i], i, philo) == -1)
			return (-1);
		i++;
	}
	if (ac == 5)
		philo->nb_eat = -1;
	return (0);
}

void	*ft_philo(void *param)
{
	t_thread		*philo;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	philo = param;
	while ((philo->info->nb_eat > philo->limit_eat) || \
	philo->info->nb_eat == -1)
	{
		ft_do_eat(philo);
		if (philo->info->bool_die == 1)
			return (0);
		ft_do_sleep(philo);
		if (philo->info->bool_die == 1)
			return (0);
	}
	return (NULL);
}

void	cut(t_philo philo, pthread_t *thread, t_thread *thread_strc)
{
	int	i;

	i = -1;
	while (++i < philo.nb_philo)
		pthread_join(thread[i], NULL);
	free(thread);
	free(thread_strc);
}

int	main(int ac, char **av)
{
	t_philo			philo;
	pthread_t		*thread;
	t_thread		*thread_strc;
	struct timeval	tv;
	int				i;

	if (ac < 5 || ac > 6)
		return (fprintf(stderr, "Bad number of arguments\n"));
	ft_init_struc(&philo);
	if (ft_parsing(av, ac, &philo) == -1)
		return (fprintf(stderr, "Bad format of arguments\n"));
	thread_strc = malloc(sizeof(t_thread) * philo.nb_philo);
	thread = malloc(sizeof(pthread_t) * philo.nb_philo);
	i = -1;
	gettimeofday(&tv, NULL);
	philo.start = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	while (++i < philo.nb_philo)
	{
		ft_init_struct_thread(thread_strc, i, &philo);
		pthread_create(&thread[i], NULL, ft_philo, &thread_strc[i]);
		usleep(1);
	}
	cut(philo, thread, thread_strc);
	return (0);
}
