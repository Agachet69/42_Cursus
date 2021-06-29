/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:55:51 by agachet           #+#    #+#             */
/*   Updated: 2021/06/29 20:07:36 by agachet          ###   ########.fr       */
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
	philo->cmpt = -1;
}

//int	ft_sleep(t_philo *philo)
//{
//	//printf("**temps** : %d is thinking", ?);
//	//usleep(???);
//	//printf("**temps** : %d is sleeping", ?);
//	//usleep(philo->t_sleep);
//}

//int	ft_fork(t_philo *philo)
//{
//	int	nb_fork;
//	pthread_mutex_t mutex;

//	pthread_mutex_init(&mutex, NULL);
//	nb_fork = philo->nb_philo;
//	while (/*usleep(philo->t_die)*/)
//	{
//		//if (nb_fork < 2)
//		//	pthread_mutex_lock(&mutex);
//		if (nb_fork >= 2)
//		{
//			nb_fork -= 2;
//			if (nb_fork < 2)
//				pthread_mutex_lock(&mutex);
//		//	printf("**temps** : %d is eating", ?);
//			usleep(philo->t_eat);
//			nb_fork += 2;
//			pthread_mutex_unlock(&mutex);
//			return (0);
//		}
//	}
//	//printf("**temps** : %d is dead", ?);
//	return (-1);
//}

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

void	*ft_philo(void *param)
{
	t_thread	*philo;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	philo = param;
	//printf("%d - %ld\n", philo->info->i, philo->info->nb_eat);
	while (philo->info->nb_eat > philo->info->i)
	{
		pthread_mutex_lock(&mutex);
		philo->info->i++;
		printf("i = %d\n", philo->info->i);
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	pthread_t	*thread;
	t_thread	*thread_strc;
	int			i;

	if (ac < 5 || ac > 6)
		return (printf("NB ARG - Error\n"));
	ft_init_struc(&philo);
	if (ft_parsing(av, ac, &philo) == -1)
		return (printf("FORMAT ARG - Error\n"));
	thread_strc = malloc(sizeof(thread_strc) * philo.nb_philo);
	thread = malloc(sizeof(pthread_t) * philo.nb_philo);
	//ft_init_struct_thread();
	i = -1;
	while (++i < philo.nb_philo)
	{
		thread_strc[i].i = i;
		thread_strc[i].info = &philo;
		pthread_create(&thread[i], NULL, ft_philo, &thread_strc[i]);
	}
	i = -1;
	while (++i < philo.nb_philo)
		pthread_join(thread[i], NULL);
	return (0);
}

