/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:56:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/23 20:03:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* checks and displays if all philosophers have eaten */
static void	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	if (read_mutex(&data->death) || data->must_eat < 0)
		return ;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->must_eat)
			return ;
	}
	pthread_mutex_lock(&data->write.mutex);
	printf("All philosophers have eaten\n");
	pthread_mutex_unlock(&data->write.mutex);
}

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->meal_count_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->death.mutex);
	pthread_mutex_destroy(&data->write.mutex);
}

void	clean_data(t_data *data)
{
	is_all_fed(data);
	destroy_mutexes(data);
	free(data->fork);
	free(data->philo);
	free(data);
}
