/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:56:30 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 18:05:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->fork[i]);
}

void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	free(data->time);
	destroy_mutexes(data);
	free(data);
	// while (++i < data->nb_philos)
	// 	free(data->fork[i]);
}
