/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:29:12 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 03:30:05 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo, int i)
{
	int	next_fork;

	next_fork = (i + 1) % philo->data->nb_philos;
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->fork[next_fork]);
		update_status(TAKE_FORK, philo, FALSE, FALSE);
		pthread_mutex_lock(&philo->data->fork[i]);
		update_status(TAKE_FORK, philo, FALSE, FALSE);
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[i]);
		update_status(TAKE_FORK, philo, FALSE, FALSE);
		pthread_mutex_lock(&philo->data->fork[next_fork]);
		update_status(TAKE_FORK, philo, FALSE, FALSE);
	}
}

static void	put_forks(t_philo *philo, int i)
{
	int	next_fork;

	next_fork = (i + 1) % philo->data->nb_philos;
	if (i % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->fork[i]);
		pthread_mutex_unlock(&philo->data->fork[next_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork[next_fork]);
		pthread_mutex_unlock(&philo->data->fork[i]);
	}
}

void	eat_action(t_philo *philo, int i)
{
	take_forks(philo, i);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	update_status(EAT, philo, FALSE, FALSE);
	ft_usleep(philo->data->time.eat);
	pthread_mutex_lock(&philo->data->meal_count_mutex);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->data->meal_count_mutex);
	put_forks(philo, i);
}
