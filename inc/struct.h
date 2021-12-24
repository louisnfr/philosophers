/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:31:21 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 03:09:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
	SUCCESS = 1,
	FAILURE = 0,
}	t_bool;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				value;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				last_meal;
	pthread_t		thread;
	pthread_t		death_thread;
	pthread_t		all_fed_thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_time
{
	int	start;
	int	die;
	int	eat;
	int	sleep;
}	t_time;

typedef struct s_data
{
	int				nb_philos;
	int				must_eat;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	t_time			time;
	t_mutex			death;
	t_mutex			write;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	meal_count_mutex;
	pthread_mutex_t	one_died;
}	t_data;

#endif
