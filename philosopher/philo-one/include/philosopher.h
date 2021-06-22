/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:21:14 by agachet           #+#    #+#             */
/*   Updated: 2021/06/22 18:45:16 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_test
{
	int i;
}				t_test;

typedef struct s_philo
{
	int			i;
	int			*j;
	int			cmpt;
	int			nb_philo;
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
	long int	nb_eat;
	t_test		*test;
}				t_philo;

#endif
