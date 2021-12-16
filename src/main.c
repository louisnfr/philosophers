/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 17:34:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->fork[i]);
}

void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		free(data->fork[i]);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	// create_philos(data);
	// // check_death(data); //check si death ou allfed
	// join_philos(data);
	// destroy_mutexes(data);
	clean_data(data);
	return (0);
}
