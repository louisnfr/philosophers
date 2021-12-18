/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:33:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 02:21:56 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(char *msg, t_philo *philo)
{
	long	time;

	time = get_time() - philo->data->time->start;
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->write);
	printf(" %-6lu ms | N°: %-3d | %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	prompt(void)
{
	printf("-----------------------------------------\n"
			"|   TIME   |    N°   |      ACTION      |\n"
			"-----------------------------------------\n");
}
