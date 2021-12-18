/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:33:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_action(t_philo *philo)
{
	update_status(SLEEP, philo);
	ft_usleep(philo->data->time.sleep);
}

static void	think_action(t_philo *philo)
{
	update_status(THINK, philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		eat_action(philo, philo->id);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}
