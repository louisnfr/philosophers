/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 02:16:25 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	create_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->philo)
		return (failure);
	i = -1;
	while (++i < data->nb_philos)
	{
		init_philo(&data->philo[i], i, data);
		pthread_mutex_init(&data->fork[i], NULL);
		pthread_create(&data->philo[i].thread, NULL,
			&routine, &data->philo[i]);
	}
	return (success);
}

t_bool	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philo[i].thread, NULL);
	return (success);
}
