/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 13:46:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_action(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	update_status(SLEEP, philo, FALSE, FALSE);
	ft_usleep(data->time.sleep);
}

static void	think_action(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	update_status(THINK, philo, FALSE, FALSE);
}

/* activity of each philosopher */
void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = arg;
	data = philo->data;
	if (data->nb_philos == 1)
		update_status(TAKE_FORK, philo, FALSE, FALSE);
	while ((philo->meal_count < data->must_eat || !data->must_eat)
		&& !read_mutex(&data->death) && data->nb_philos > 1)
	{
		eat_action(philo, philo->id);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}
