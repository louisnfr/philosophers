/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:28:10 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 23:28:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_dinner *dinner)
{
	int	i;

	i = -1;
	while (++i < dinner->nb_philos)
		pthread_mutex_destroy(&dinner->fork[i]);
}

int	main(int ac, char **av)
{
	t_dinner	*dinner;

	dinner = init_dinner(ac, av);
	create_philos(dinner);
	// check_death(dinner); //check si death ou allfed
	join_philos(dinner);
	destroy_mutexes(dinner);
	return (0);
}
