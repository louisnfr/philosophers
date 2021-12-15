/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:31:21 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 23:29:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_philo
{
	int				id;
	int				has_eaten;
	int				forks;
	// int				left_fork;
	// int				right_fork;
	unsigned long	last_meal;
	pthread_t		thread;
	struct s_dinner *dinner;
} t_philo;

typedef struct s_dinner
{
	int				nb_philos;
	unsigned long	start_time;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				nb_eat;
	t_bool			all_fed;
	t_bool			death;
	pthread_mutex_t	*fork;
	t_philo			*philo;
} t_dinner;

#endif
