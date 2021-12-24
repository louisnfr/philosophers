/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 01:25:10 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_time	init_time(char **av, t_data *data)
{
	t_time	time;

	(void)data;
	time.start = get_time();
	time.die = ft_atoi(av[2]);
	time.eat = ft_atoi(av[3]);
	time.sleep = ft_atoi(av[4]);
	return (time);
}

static pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!forks)
		return (NULL);
	return (forks);
}

static void	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->fork[i], NULL);
	pthread_mutex_init(&data->death.mutex, NULL);
	pthread_mutex_init(&data->write.mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->meal_count_mutex, NULL);
	write_mutex(&data->write, TRUE);
	write_mutex(&data->death, FALSE);
}

static void	init_values(t_data *data, char **av)
{
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = 0;
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	if (!check_input(ac, av))
	{
		ft_putstr_fd(2, "error: invalid arguments\n");
		return (NULL);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philos = ft_atoi(av[1]);
	data->fork = init_forks(data);
	data->time = init_time(av, data);
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philo)
		return (NULL);
	init_values(data, av);
	init_mutexes(data);
	return (data);
}
