/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 15:07:08 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time	*init_time(char **av, t_data *data)
{
	t_time	*time;

	(void)data;
	time = malloc(sizeof(t_time));
	if (!time)
		exit_error("time malloc()", 1);
	time->start = gettime();
	time->to_die = ft_atoi(av[2]) * 1000;
	time->to_eat = ft_atoi(av[3]) * 1000;
	time->to_sleep = ft_atoi(av[4]) * 1000;
	return (time);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	if (ac != 6)
		exit_error("wrong input", 1);

	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("data malloc()", 1);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->fork)
		exit_error_free(data, "fork malloc()", 1);

	data->nb_philos = ft_atoi(av[1]);
	data->is_all_fed = false;
	data->is_one_died = false;
	init_time(av, data);
	data->must_eat = ft_atoi(av[5]);
	return (data);
}

t_bool	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal_time = 0;
	philo->meals_count = 0;
	philo->data = data;
	return (success);
}
