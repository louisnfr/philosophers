/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 01:24:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time	*init_time(char **av, t_data *data)
{
	t_time	*time;

	(void)data;
	time = malloc(sizeof(t_time));
	if (!time)
		exit_error("time malloc()", EXIT_FAILURE);
	time->start = get_time();
	time->die = ft_atoi(av[2]);
	time->eat = ft_atoi(av[3]);
	time->sleep = ft_atoi(av[4]);
	return (time);
}

static pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!forks)
		exit_error("fork malloc()", EXIT_FAILURE);
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = malloc(sizeof(t_data));
	data->nb_philos = ft_atoi(av[1]);
	data->fork = init_forks(data);
	data->time = init_time(av, data);
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->is_all_fed = FALSE;
	data->is_one_died = FALSE;
	return (data);
}
