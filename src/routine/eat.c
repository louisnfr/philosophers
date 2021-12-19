/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:29:12 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 01:54:36 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->fork[i]);
	pthread_mutex_lock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
	update_status(TAKE_FORK, philo);
	update_status(TAKE_FORK, philo);
	return (0);
}

static void	put_forks(t_philo *philo, int i)
{
	pthread_mutex_unlock(&philo->data->fork[i]);
	pthread_mutex_unlock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
}

void	eat_action(t_philo *philo, int i)
{
	if (take_forks(philo, i) == 0)
	{
		philo->last_meal = get_time() - philo->data->time.start;
		update_status(EAT, philo);
		ft_usleep(philo->data->time.eat);
		philo->meal_count++;
		put_forks(philo, i);
	}
}
