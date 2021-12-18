/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 00:37:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal = 0;
	philo->meal_count = 0;
	philo->data = data;
}

void	*is_dead(void *arg)
{
	t_philo *philo;
	long	time;

	philo = arg;
	ft_usleep(philo->data->time.die);
	time = get_time() - philo->data->time.start;
	if (time - philo->last_meal >= philo->data->time.die)
	{
		update_status(DIED, philo);
		write_mutex(&philo->data->write, 0);
		write_mutex(&philo->data->death, 1);
	}
	return (NULL);
}

t_bool	create_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		init_philo(&data->philo[i], i, data);
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]))
			exit_error("pthread_create()", EXIT_FAILURE);
		if (pthread_create(&data->philo[i].death_thread, NULL, &is_dead, &data->philo[i]))
			exit_error("pthread_create()", EXIT_FAILURE);
	}
	return (SUCCESS);
}

void	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		pthread_join(data->philo[i].death_thread, NULL);
	}
}
