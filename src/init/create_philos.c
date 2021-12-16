/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:01:13 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 02:01:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	create_philos(t_dinner *dinner)
{
	int	i;

	dinner->philo = malloc(sizeof(pthread_t) * dinner->nb_philos);
	if (!dinner->philo)
		return (failure);
	i = -1;
	while (++i < dinner->nb_philos)
	{
		init_philo(&dinner->philo[i], i, dinner);
		pthread_mutex_init(&dinner->fork[i], NULL);
		pthread_create(&dinner->philo[i].thread, NULL,
			&routine, &dinner->philo[i]);
	}
	return (success);
}

t_bool	join_philos(t_dinner *dinner)
{
	int	i;

	i = -1;
	while (++i < dinner->nb_philos)
		pthread_join(dinner->philo[i].thread, NULL);
	return (success);
}
