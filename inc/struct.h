/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:31:21 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 02:20:08 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_count;
	unsigned long	last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
} t_philo;

typedef struct s_time
{
	unsigned long	start;
	unsigned long	to_die;
	unsigned long	to_eat;
	unsigned long	to_sleep;
}	t_time;

typedef struct s_data
{
	int				nb_philos;
	int				must_eat;
	t_bool			is_all_fed;
	t_bool			one_died;
	t_time			*time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
} t_data;

#endif
