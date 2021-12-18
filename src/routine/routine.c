/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 02:27:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(philo->data->time->eat / 10);
	while (!philo->data->is_one_died)
	{
		eat_action(philo, philo->id);
		sleep_action(philo);
		think_action(philo);
	}
	return (NULL);
}
