/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 01:47:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->last_meal = 0;
	philo->meal_count = 0;
	philo->data = data;
}

/* thread to check continuously if the philosopher is dead */
static void	*is_dead(void *arg)
{
	t_data *data;
	t_philo *philo;
	long	time;

	philo = arg;
	data = philo->data;
	ft_usleep(data->time.die);
	time = get_time() - data->time.start;
	while ((!data->must_eat || philo->meal_count < data->must_eat)
		&& read_mutex(&data->death) == FALSE)
	{
		if (time - philo->last_meal >= data->time.die)
		{
			update_status(DIED, philo);
			write_mutex(&data->write, FALSE);
			write_mutex(&data->death, TRUE);
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
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]))
			exit_error("pthread_create()", EXIT_FAILURE);
		if (pthread_create(&data->philo[i].death_thread, NULL, &is_dead, &data->philo[i]))
			exit_error("pthread_create()", EXIT_FAILURE);
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
