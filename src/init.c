/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 18:30:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_dinner	*init_dinner(int ac, char **av)
{
	t_dinner	*dinner;

	if (ac != 6)
		exit_error("wrong input", 1);
	dinner = malloc(sizeof(t_dinner));
	if (!dinner)
		exit_error("init malloc()", 1);

	dinner->nb_philos = ft_atoi(av[1]);
	dinner->all_fed = FALSE;
	dinner->death = FALSE;
	dinner->start_time = gettime();
	dinner->time_to_die = ft_atoi(av[2]);
	dinner->time_to_eat = ft_atoi(av[3]);
	dinner->time_to_sleep = ft_atoi(av[4]);
	dinner->nb_eat = ft_atoi(av[5]);
	return (dinner);
}

t_bool	init_philo(t_philo *philo, int i, t_dinner *dinner)
{
	philo->id = i;
	philo->forks = 0;
	philo->last_meal = 0;
	philo->has_eaten = 0;
	philo->dinner = dinner;
}

t_bool	create_philos(t_dinner *dinner)
{
	int	i;

	dinner->philo = malloc(sizeof(pthread_t) * dinner->nb_philos);
	if (!dinner->philo)
		return (FAILURE);
	i = -1;
	while (++i < dinner->nb_philos)
	{
		init_philo(dinner->philo[i]);
		pthread_create(&dinner->philo[i].thread, NULL, &routine, dinner->philo);
	}
	return (SUCCESS);
}

t_bool	join_philos(t_dinner *dinner)
{
	int	i;

	i = -1;
	while (++i < dinner->nb_philos)
	{
		pthread_join(dinner->philo[i].thread, NULL);
	}
	return (SUCCESS);
}
