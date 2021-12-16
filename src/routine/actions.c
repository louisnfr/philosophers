/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:22:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 02:25:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	eat_action(t_philo *philo, int i)
{
	// if ((gettime() - philo->data->start_time) - philo->last_meal > philo->data->time_to_die)
	// {
	// 	philo->data->one_died = true;
	// 	return (failure);
	// }
	pthread_mutex_lock(&philo->data->fork[i]);
	update_status(FORK, philo);
	pthread_mutex_lock(&philo->data->fork[i + 1]);
	update_status("has taken a fork", philo);
	update_status("is eating", philo);
	usleep(philo->data->time->to_eat);
	philo->last_meal_time = gettime();
	philo->meals_count++;
	check_death(philo->data);
	pthread_mutex_unlock(&philo->data->fork[i]);
	pthread_mutex_unlock(&philo->data->fork[i + 1]);
	return (success);
}

void	sleep_action(t_philo *philo)
{
	update_status("is sleeping", philo);
	usleep(philo->data->time->to_sleep);
}

