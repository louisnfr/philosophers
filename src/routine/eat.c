/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:29:12 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 23:41:18 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	try_fork(t_philo *philo, int i)
{
	(void)philo;
	(void)i;
}

t_bool	eat_action(t_philo *philo, int i)
{
	is_dead(philo);
	try_fork(philo, i);
	pthread_mutex_lock(&philo->data->fork[i]);
	update_status(TAKE_FORK, philo);
	pthread_mutex_lock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
	update_status(TAKE_FORK, philo);
	update_status(EAT, philo);
	usleep(philo->data->time->to_eat);
	philo->last_meal_time = gettime() - philo->data->time->start;
	philo->meals_count++;
	is_all_fed(philo->data);
	pthread_mutex_unlock(&philo->data->fork[i]);
	pthread_mutex_unlock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
	return (SUCCESS);
}
