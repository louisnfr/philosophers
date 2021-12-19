/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:33:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 01:44:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(char *msg, t_philo *philo)
{
	t_data	*data;
	long	time;

	data = philo->data;
	time = get_time() - data->time.start;
	pthread_mutex_lock(&data->write.mutex);
	if (data->write.value == TRUE)
		printf(" %-6lu ms | %4d | %s\n", time, philo->id + 1, msg);
	pthread_mutex_unlock(&data->write.mutex);
}

void	prompt(void)
{
	ft_putstr_fd(1, "--------------------------------------\n"
		"|   TIME   |  N°  |      ACTION      |\n"
		"--------------------------------------\n");
}
