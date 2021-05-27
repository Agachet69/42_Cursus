/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:55:51 by agachet           #+#    #+#             */
/*   Updated: 2021/05/27 19:34:58 by agachet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"


void	ft_init_struc(t_philo *philo)
{
	philo->i = 0;
	philo->nb_philo = 0;
	philo->t_die = 0;
	philo->t_eat = 0;
	philo->t_sleep = 0;
	philo->nb_eat = -1;
}

int	ft_sleep(t_philo *philo)
{
	printf("**temps** : %d is thinking", ?);
	usleep(???);
	printf("**temps** : %d is sleeping", ?);
	usleep(philo->t_sleep);
}

int	ft_fork(t_philo *philo)
{
	int	nb_fork;
	pthread_mutex_t mutex;


	pthread_mutex_init(&mutex, NULL);
	nb_fork = philo->nb_philo;
	while (/*usleep(philo->t_die)*/)
	{
		if (nb_fork < 2)
			pthread_mutex_lock(&mutex);
		if (nb_fork >= 2)
		{
			nb_fork -= 2;
			printf("**temps** : %d is eating", ?);
			usleep(philo->t_eat);
			nb_fork += 2;
			if (nb_fork == 2 || nb_fork == 3)
				pthread_mutex_unlock(&mutex);
			return (0);
		}
	}
	printf("**temps** : %d is dead", ?);
	return (-1);
}

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
	return (0);
}

int	ft_philo(t_philo *philo)
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	while (philo->i != (philo->nb_eat * philo->nb_philo))
	{
		if (ft_fork(&philo) == -1)
			return (printf("Un philosopher est mort de faim\n"));
		ft_sleep(&philo);
		pthread_mutex_lock(&mutex);
		philo->i++;
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	pthread_t	*thread;
	int			j;

	j = 0;
	if (ac < 5 || ac > 6)
		return (printf("NB ARG - Error\n"));
	ft_init_struc(&philo);
	if (ft_parsing(av, ac, &philo) == -1)
		return (printf("FORMAT ARG - Error\n"));
	while (j < philo.nb_philo)
	{
			pthread_create(&thread[j], NULL, ft_philo, &philo);
			j++;
	}
	if (philo.i != philo.nb_eat)
		return (printf("Un philosopher est mort de faim\n"));
	// while (i != philo.nb_eat)
	// {
	// 	if (ft_fork(&philo) == -1)
	// 		return (printf("Un philosopher est mort de faim\n"));
	// 	ft_sleep(&philo);
	// 	i++;
	// }
	return (0);
}

