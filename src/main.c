/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 13:45:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	prompt();
	create_philos(data);
	join_philos(data);
	clean_data(data);
}
