/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 23:07:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	prompt();
	create_philos(data);
	// // check_death(data); //check si death ou allfed
	join_philos(data);
	// destroy_mutexes(data);
	// clean_data(data);
	return (0);
}
