/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:14:41 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 17:19:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	if (ac != 6)
		exit_error("wrong input", 1);
	data = malloc(sizeof(t_data));
	if (!data)
		exit_error("init malloc()", 1);
	data->death = FALSE;
	data->nb_philos = ft_atoi(av[1]);
	return (data);
}

t_bool	create_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->philo)
		return (FAILURE);
	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, &routine, data);
	}
	return (SUCCESS);
}

t_bool	join_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_join(data->philo[i], NULL);
	}
	return (SUCCESS);
}
