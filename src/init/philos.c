/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 00:02:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal = get_time();
	philo->meal_count = 0;
	philo->data = data;
}

/* thread to check continuously if the philosopher is dead */
static void	*death(void *arg)
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

t_bool	create_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		init_philo(&data->philo[i], i, data);
		if (pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]))
			exit_error_free("pthread_create()", EXIT_FAILURE, data);
		if (pthread_create(&data->philo[i].death_thread, NULL,
				&death, &data->philo[i]))
			exit_error_free("pthread_create()", EXIT_FAILURE, data);
	}
	return (SUCCESS);
}

void	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		pthread_join(data->philo[i].death_thread, NULL);
	}
}
