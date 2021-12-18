/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:27:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:08:43 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *arg)
{
	t_philo *philo;
	long	time;

	philo = arg;
	ft_usleep(philo->data->time.die + 1);
	time = get_time() - philo->data->time.start;
	pthread_mutex_lock(&philo->data->eat_mtx);
	if (time - philo->last_meal >= philo->data->time.die)
	{
		pthread_mutex_unlock(&philo->data->eat_mtx);
		update_status(DIED, philo);
		// exit(0);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->data->eat_mtx);
	return (NULL);
}

t_bool	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meal_count < data->must_eat)
			return (FALSE);
	}
	pthread_mutex_lock(&data->write);
	printf("all the philosophers ate\n");
	pthread_mutex_unlock(&data->write);
	clean_data(data);
	return (SUCCESS);
}
