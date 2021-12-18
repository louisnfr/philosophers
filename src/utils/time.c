/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:23:45 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:31:07 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* returns time in ms */
long	get_time(void)
{
	struct timeval	time;
	long			ret;

	if (gettimeofday(&time, NULL) < 0)
		exit_error("gettimeofday()", EXIT_FAILURE);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

/* usleep but more precise and in ms */
void	ft_usleep(long ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(ms / 10);
}
