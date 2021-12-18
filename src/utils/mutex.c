/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:07:52 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 00:13:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_mutex(t_mutex *t_mutex, int value)
{
	pthread_mutex_lock(&t_mutex->mutex);
	t_mutex->value = value;
	pthread_mutex_unlock(&t_mutex->mutex);
}

int	read_mutex(t_mutex *t_mutex)
{
	int	value;

	pthread_mutex_lock(&t_mutex->mutex);
	value = t_mutex->value;
	pthread_mutex_unlock(&t_mutex->mutex);
	return (value);
}
