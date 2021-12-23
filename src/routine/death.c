/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:44:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 00:44:12 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* thread to check continuously if the philosopher is dead */
void	*death(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		time;

	philo = arg;
	data = philo->data;
	while (/*!data->must_eat && */read_mutex(&data->death) == FALSE)
	{
		pthread_mutex_lock(&philo->data->meal_count_mutex);
		if (!(philo->meal_count < data->must_eat || !data->must_eat))
		{
			pthread_mutex_unlock(&philo->data->meal_count_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->meal_count_mutex);
		pthread_mutex_lock(&philo->data->meal_mutex);
		time = get_time() - philo->last_meal;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		if (time > data->time.die)
		{
			update_status(DIED, philo, TRUE);
			write_mutex(&data->death, TRUE);
			return (NULL);
		}
	}
	return (NULL);
}
