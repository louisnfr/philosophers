/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 17:39:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	eat()

void	*routine(void *arg)
{
	t_dinner	*dinner;

	dinner = arg;
	while (!dinner->death)
	{
		//eating(philo);
		// if (philo->dinner->all_fed == 1)
			//break;
		//make_him_sleep(philo);
		//printf("is thinking");
		printf("eating\n");
		usleep(1000000);
		printf("sleep\n");
		usleep(1000000);
		printf("think\n");
		usleep(1000000);
		dinner->death = TRUE;
	}
	return (NULL);
}
