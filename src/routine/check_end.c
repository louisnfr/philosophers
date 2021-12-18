/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:27:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 14:23:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_dead(t_philo *philo)
{
	long	time;

	// pthread_mutex_lock(&philo->data->death);
	time = get_time() - philo->data->time->start;
	if (time - philo->last_meal_time > philo->data->time->die)
	{
		update_status(DIED, philo);
		philo->data->is_one_died = TRUE;
		// pthread_mutex_unlock(&philo->data->death);
		exit(0);
		return (SUCCESS);
	}
	// pthread_mutex_unlock(&philo->data->death);
	return (FAILURE);
}

t_bool	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meals_count < data->must_eat)
			return (FALSE);
	}
	printf("all the philosophers ate\n");
	exit (0);
	return (SUCCESS);
}
