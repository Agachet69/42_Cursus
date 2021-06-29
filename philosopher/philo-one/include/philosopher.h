/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:21:14 by agachet           #+#    #+#             */
/*   Updated: 2021/06/29 20:04:35 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_philo
{
	int			fork;
	int			i;
	int			cmpt;
	int			nb_philo;
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
	long int	nb_eat;
}				t_philo;

typedef struct s_thread
{
	int i;
	t_philo *info;
}				t_thread;

#endif
