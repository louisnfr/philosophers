/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:33:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:42:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(char *msg, t_philo *philo)
{
	long	time;

	time = get_time() - philo->data->time.start;
	pthread_mutex_lock(&philo->data->write);
	printf(" %-6lu ms | %4d | %s\n", time, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	prompt(void)
{
	ft_putstr_fd(1, "--------------------------------------\n"
		"|   TIME   |  N°  |      ACTION      |\n"
		"--------------------------------------\n");
}
