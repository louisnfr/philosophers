/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 19:10:35 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

 t_time	*init_time(char **av, t_data *data)
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

	check_input(ac, av);
	data = malloc(sizeof(t_data));
	data->nb_philos = ft_atoi(av[1]);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	data->time = init_time(av, data);
	data->must_eat = ft_atoi(av[5]);
	data->is_all_fed = FALSE;
	data->is_one_died = FALSE;
	return (data);
}
