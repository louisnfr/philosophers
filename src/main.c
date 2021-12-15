/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 14:57:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void)
{
	while (1)
	{
		printf("eat\n");
		usleep(1000000);
		printf("sleep\n");
		usleep(1000000);
		printf("think\n");
		usleep(1000000);
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	pthread_t p;
	pthread_mutex_t mutex;

	pthread_create(&p, NULL, &start, NULL);
	pthread_join(p, NULL);
	return (0);
}
