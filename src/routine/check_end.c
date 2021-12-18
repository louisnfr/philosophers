/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:27:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 00:45:46 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_all_fed(t_data *data)
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
