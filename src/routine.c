/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:13:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 16:20:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data;

	data = arg;
	while (!data->death)
	{
		printf("eating\n");
		usleep(1000000);
		printf("sleep\n");
		usleep(1000000);
		printf("think\n");
		usleep(1000000);
		data->death = TRUE;
	}
	return (NULL);
}
