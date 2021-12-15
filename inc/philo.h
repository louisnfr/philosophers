/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:27:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 17:28:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# include "utils.h"

typedef struct s_philo
{
	int id;
	int has_eaten;
	int left_fork;
	int right_fork;
	long long int last_meal;
	pthread_t thread;
	struct s_dinner *dinner;
} t_philo;

typedef struct s_dinner
{
	int num_philo;
	int time_to_die;
	int all_fed;
	int is_dead;
	pthread_mutex_t *fork;
	t_philo *philo;
} t_dinner;

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0,
	SUCCESS = 1,
	FAILURE = 0,
}	t_bool;

typedef struct s_data
{
	pthread_t	*philo;
	int			nb_philos;
	int			forks;
	t_bool		death;

}	t_data;

t_data	*init_data(int ac, char **av);
int		ft_atoi(char *s);
void	*routine(void *arg);

t_bool	create_philos(t_data *data);
t_bool	join_philos(t_data *data);


#endif
