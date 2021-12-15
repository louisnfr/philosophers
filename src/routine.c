/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 23:32:52 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	p_eat(t_philo *philo, int i)
{
	if ((gettime() - philo->dinner->start_time) - philo->last_meal > philo->dinner->time_to_die)
	{
		philo->dinner->death = true;
		return (failure);
	}
	pthread_mutex_lock(&philo->dinner->fork[i]);
	pthread_mutex_lock(&philo->dinner->fork[i + 1]);
	printf("%lu %d has taken a fork\n",
		gettime() - philo->dinner->start_time, philo->id);
	printf("%lu %d is eating\n",
		gettime() - philo->dinner->start_time, philo->id);
	usleep(philo->dinner->time_to_eat);
	philo->last_meal = gettime();
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->dinner->fork[i]);
	pthread_mutex_unlock(&philo->dinner->fork[i + 1]);
	return (success);
}

static void	p_sleep(t_philo *philo)
{
	usleep(philo->dinner->time_to_sleep);
	printf("%lu %d is sleeping\n",
		gettime() - philo->dinner->start_time, philo->id);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->dinner->death)
	{
		if (!p_eat(philo, philo->id) || philo->dinner->all_fed)
			break ;
		p_sleep(philo);
		printf("%lu %d is thinking\n",
			gettime() - philo->dinner->start_time, philo->id);
	}
	return (NULL);
}
