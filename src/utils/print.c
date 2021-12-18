/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:33:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 18:15:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(char *msg, t_philo *philo)
{
	long	time;

	time = get_time() - philo->data->time->start;
	if (philo->data->is_one_died || philo->data->is_all_fed)
		return ;
	pthread_mutex_lock(&philo->data->write);
	printf(" %-6lu ms | N°: %-3d | %s\n", time, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	prompt(void)
{
	printf("-----------------------------------------\n"
		"|   TIME   |    N°   |      ACTION      |\n"
		"-----------------------------------------\n");
}
