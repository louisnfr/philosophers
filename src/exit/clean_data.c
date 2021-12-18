/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:56:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 00:46:46 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->must_eat)
			return ;
	}
	pthread_mutex_lock(&data->write.mutex);
	printf("all the philosophers ate\n");
	pthread_mutex_unlock(&data->write.mutex);
}

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->fork[i]);
}

void	clean_data(t_data *data)
{
	is_all_fed(data);
	destroy_mutexes(data);
	free(data->fork);
	free(data->philo);
	free(data);
	exit(0);
}
