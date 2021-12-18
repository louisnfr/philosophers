/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 01:31:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(t_data *data)
{
	// while (!data->is_one_died)
	// 	ft_usleep(1);
	join_philos(data);
	clean_data(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	prompt();
	create_philos(data);
	end(data);
}
