/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:44:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 03:51:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* checks and displays if all philosophers have eaten */
static t_bool	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	if (read_mutex(&data->death) || data->must_eat < 0)
		return (FALSE);
	pthread_mutex_lock(&data->meal_count_mutex);
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->must_eat)
		{
			pthread_mutex_unlock(&data->meal_count_mutex);
			return (FALSE);
		}
	}
	pthread_mutex_unlock(&data->meal_count_mutex);
	return (TRUE);
}

/* thread to check continuously if the philosopher is dead */
void	*death(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		time;

	philo = arg;
	data = philo->data;
	while (/*!is_all_fed(data) && */read_mutex(&data->death) == FALSE)
	{
		pthread_mutex_lock(&data->meal_count_mutex);
		if (!(philo->meal_count < data->must_eat || !data->must_eat))
		{
			pthread_mutex_unlock(&data->meal_count_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->meal_count_mutex);
		pthread_mutex_lock(&data->meal_mutex);
		time = get_time() - philo->last_meal;
		pthread_mutex_unlock(&data->meal_mutex);
		if (time > data->time.die)
		{
			update_status(DIED, philo, TRUE, FALSE);
			write_mutex(&data->death, TRUE);
			pthread_mutex_unlock(&data->one_died);
			return (NULL);
		}
	}
	return (NULL);
}

/* thread to check continuously if all philosophers have eaten */
void	*all_fed(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = arg;
	data = philo->data;
	while (data->must_eat && read_mutex(&data->death) == FALSE)
	{
		if (is_all_fed(data) == TRUE)
		{
			update_status(ALL_FED, philo, TRUE, TRUE);
			pthread_mutex_unlock(&data->one_died);
			return (NULL);
		}
	}
	return (NULL);
}
