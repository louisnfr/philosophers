/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:22:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 23:11:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat_action(t_philo *philo, int i)
{
	// if ((gettime() - philo->data->start_time) - philo->last_meal > philo->data->time_to_die)
	// {
	// 	philo->data->is_one_died = TRUE;
	// 	return (FAILURE);
	// }
	pthread_mutex_lock(&philo->data->fork[i]);
	update_status(TAKE_FORK, philo);
	pthread_mutex_lock(&philo->data->fork[i + 1]);
	update_status(TAKE_FORK, philo);
	update_status(EAT, philo);
	usleep(philo->data->time->to_eat);
	philo->last_meal_time = gettime();
	philo->meals_count++;
	check_death(philo->data);
	pthread_mutex_unlock(&philo->data->fork[i]);
	pthread_mutex_unlock(&philo->data->fork[i + 1]);
	return (SUCCESS);
}

void	sleep_action(t_philo *philo)
{
	update_status(SLEEP, philo);
	usleep(philo->data->time->to_sleep);
}
