/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 15:58:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void)arg;
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
	t_data	*data;

	data = init_data(ac, av);
	// create_philos();
	return (0);
}

	// pthread_create(&p, NULL, &routine, NULL);
	// pthread_join(p, NULL);
