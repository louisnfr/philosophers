/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/22 17:48:56 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_action(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_mutex(&data->write) == TRUE)
	{
		update_status(SLEEP, philo);
		ft_usleep(data->time.sleep);
	}
}

static void	think_action(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (read_mutex(&data->write) == TRUE)
		update_status(THINK, philo);
}

/* activity of each philosopher */
void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(5);
	while ((!data->must_eat || philo->meal_count < data->must_eat)
		&& read_mutex(&data->death) == FALSE && data->nb_philos > 1)
	{
		// printf("check\n");
		eat_action(philo, philo->id);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}
