/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 01:50:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal_time = 0;
	philo->meals_count = 0;
	philo->data = data;
}

t_bool	create_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		init_philo(&data->philo[i], i, data);
		if (pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]))
			exit_error("pthread_create()", EXIT_FAILURE);
	}
	return (SUCCESS);
}

void	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philo[i].thread, NULL);
}
