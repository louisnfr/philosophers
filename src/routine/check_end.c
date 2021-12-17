/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:27:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 23:43:19 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dead(t_philo *philo)
{
	if ((gettime() - philo->data->time->start)
		- philo->last_meal_time > philo->data->time->to_die)
	{
		update_status(DIED, philo);
		philo->data->is_one_died = TRUE;
		exit(EXIT_FAILURE);
	}
}

void	is_all_fed(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].meals_count < data->must_eat)
			return ;
	}
	printf("eve
	\n");
	exit (0);
}
