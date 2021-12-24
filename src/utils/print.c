/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:33:48 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 03:28:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(char *msg, t_philo *philo, int death, int all_fed)
{
	t_data	*data;
	int		time;

	data = philo->data;
	pthread_mutex_lock(&data->write.mutex);
	time = get_time() - data->time.start;
	if (data->write.value == TRUE)
	{
		if (death == TRUE)
			data->write.value = FALSE;
		if (all_fed == FALSE)
			printf(" %-6d ms | %4d | %s\n", time, philo->id + 1, msg);
		else
			printf(" %-6d ms | %s\n", time, msg);
	}
	pthread_mutex_unlock(&data->write.mutex);
}

void	prompt(void)
{
	ft_putstr_fd(1, "--------------------------------------\n"
		"|   TIME   |  N°  |      ACTION      |\n"
		"--------------------------------------\n");
}
