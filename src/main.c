/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 19:00:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_death(t_data *data)
// {
// 	pthread_mutex_lock(&data->death);
// 	if (data->is_one_died)
// 	{
// 		pthread_mutex_unlock(&data->death);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&data->death);
// 	return (0);
// }

void	end(t_data *data)
{
	// while (!data->is_one_died || !data->is_all_fed)
	// 	ft_usleep(1);
	join_philos(data);
	clean_data(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	// prompt();
	// create_philos(data);
	// end(data);
}
