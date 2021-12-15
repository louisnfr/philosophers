/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:31:21 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 17:45:18 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "philo.h"

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0,
	SUCCESS = 1,
	FAILURE = 0,
}	t_bool;

typedef struct s_philo
{
	int				id;
	int				has_eaten;
	int				forks;
	// int				left_fork;
	// int				right_fork;
	long long int	last_meal;
	pthread_t		thread;
	struct s_dinner *dinner;
} t_philo;

typedef struct s_dinner
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	t_bool			all_fed;
	t_bool			death;
	pthread_mutex_t	*fork;
	t_philo			*philo;
} t_dinner;

#endif
