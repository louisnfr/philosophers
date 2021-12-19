/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 01:55:35 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* activity of each philosopher */
void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = arg;
	data = philo->data;
	while ((!data->must_eat || philo->meal_count < data->must_eat)
		&& read_mutex(&data->death) == FALSE && data->nb_philos > 1)
	{
		eat_action(philo, philo->id);
		update_status(SLEEP, philo);
		ft_usleep(data->time.sleep);
		update_status(THINK, philo);
	}
	return (NULL);
}
