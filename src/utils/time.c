/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:23:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/23 02:37:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* returns time in ms */
int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		exit_error("gettimeofday()", EXIT_FAILURE);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* usleep but more precise and in ms */
void	ft_usleep(int ms)
{
	int	start;

	start = get_time();
	while (get_time() < ms + start)
		usleep(100);
}
