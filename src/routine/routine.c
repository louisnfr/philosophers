/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 00:39:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_action(t_philo *philo)
{
	update_status(SLEEP, philo);
	ft_usleep(philo->data->time.sleep);
}

static void	think_action(t_philo *philo)
{
	update_status(THINK, philo);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = arg;
	data = philo->data;
	while (!read_mutex(&data->death) && (philo->meal_count < data->must_eat))
	{
		eat_action(philo, philo->id);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}
