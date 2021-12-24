/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:44:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 13:48:21 by lraffin          ###   ########.fr       */
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
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->must_eat)
			return (FALSE);
	}
	return (TRUE);
}

/* thread to check continuously if the philosopher is dead */
void	*death(void *arg)
{
	t_philo	*philo;
	int		time;

	philo = arg;
	while (read_mutex(&philo->data->death) == FALSE)
	{
		pthread_mutex_lock(&philo->data->meal_count_mutex);
		if (!(philo->meal_count < philo->data->must_eat
				|| !philo->data->must_eat))
		{
			pthread_mutex_unlock(&philo->data->meal_count_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->meal_count_mutex);
		pthread_mutex_lock(&philo->data->meal_mutex);
		time = get_time() - philo->last_meal;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		if (time > philo->data->time.die)
		{
			update_status(DIED, philo, TRUE, FALSE);
			write_mutex(&philo->data->death, TRUE);
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
	int		are_fed;

	philo = arg;
	data = philo->data;
	while (data->must_eat && read_mutex(&data->death) == FALSE)
	{
		pthread_mutex_lock(&data->meal_count_mutex);
		are_fed = is_all_fed(data);
		pthread_mutex_unlock(&data->meal_count_mutex);
		if (are_fed == TRUE)
		{
			update_status(ALL_FED, philo, TRUE, TRUE);
			return (NULL);
		}
	}
	return (NULL);
}
