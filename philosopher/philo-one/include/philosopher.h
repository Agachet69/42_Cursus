/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:21:14 by agachet           #+#    #+#             */
/*   Updated: 2021/05/27 19:27:33 by agachet          ###   ########lyon.fr   */
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
	int			nb_philo;
	int			i;
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
	long int	nb_eat;
}				t_philo;

#endif
