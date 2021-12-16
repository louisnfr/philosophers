/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 01:54:06 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_dinner *dinner)
{
	int	i;

	i = -1;
	while (++i < dinner->nb_philos)
	{
		if (dinner->philo[i].has_eaten < dinner->nb_eat)
			return ;
	}
	exit (0);
}

static t_bool	p_eat(t_philo *philo, int i)
{
	// if ((gettime() - philo->dinner->start_time) - philo->last_meal > philo->dinner->time_to_die)
	// {
	// 	philo->dinner->death = true;
	// 	return (failure);
	// }
	pthread_mutex_lock(&philo->dinner->fork[i]);
	update_status(FORK, philo);
	pthread_mutex_lock(&philo->dinner->fork[i + 1]);
	update_status("has taken a fork", philo);
	update_status("is eating", philo);
	usleep(philo->dinner->time_to_eat);
	philo->last_meal = gettime();
	philo->has_eaten++;
	check_death(philo->dinner);
	pthread_mutex_unlock(&philo->dinner->fork[i]);
	pthread_mutex_unlock(&philo->dinner->fork[i + 1]);
	return (success);
}

static void	p_sleep(t_philo *philo)
{
	update_status("is sleeping", philo);
	usleep(philo->dinner->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->dinner->death)
	{
		p_eat(philo, philo->id);
		p_sleep(philo);
		update_status("is thinking", philo);
	}
	return (NULL);
}
