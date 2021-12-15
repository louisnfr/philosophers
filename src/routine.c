/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 18:26:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	eat(pthread_t *philo)
// {

// }

// static void	sleep(pthread_t *philo)
// {

// }

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	while (!philo->dinner->death)
	{
		// eat(dinner->philo);
		// if (philo->dinner->all_fed == 1)
			//break;
		// sleep(dinner->philo);
		printf("%-10lu %-4d is thinking\n",
			gettime() - philo->dinner->start_time, philo->id);
		usleep(1000000);
	}
	return (NULL);
}
