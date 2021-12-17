/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 18:04:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal_time = 0;
	philo->meals_count = 0;
	philo->data = data;
	return (SUCCESS);
}

t_bool	create_philos(t_data *data)
{
	int	i;

	i = -1;
	init_philo(&data->philo[i], i, data);
	while (++i < data->nb_philos)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_create(&data->philo[i].thread, NULL,
			&routine, &data->philo[i]);
	}
	return (SUCCESS);
}

t_bool	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philo[i].thread, NULL);
	return (SUCCESS);
}
