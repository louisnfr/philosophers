/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:29:12 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:19:43 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->fork[i]);
	update_status(TAKE_FORK, philo);
	pthread_mutex_lock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
	update_status(TAKE_FORK, philo);
}

static void	put_forks(t_philo *philo, int i)
{
	pthread_mutex_unlock(&philo->data->fork[i]);
	pthread_mutex_unlock(&philo->data->fork[(i + 1) % philo->data->nb_philos]);
}

t_bool	eat_action(t_philo *philo, int i)
{
	take_forks(philo, i);
	philo->last_meal = get_time() - philo->data->time.start;
	update_status(EAT, philo);
	pthread_mutex_lock(&philo->data->eat_mtx);
	ft_usleep(philo->data->time.eat);
	pthread_mutex_unlock(&philo->data->eat_mtx);
	put_forks(philo, i);
	philo->meal_count++;
	is_all_fed(philo->data);
	return (SUCCESS);
}
