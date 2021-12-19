/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:29 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 02:53:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* accepts 0 */
static t_bool is_int(char *av)
{
	int	i;

	i = -1;
	if (ft_atoi(av) > 2147483647 || ft_atoi(av) < -2147483648)
		return (FAILURE);
	while (av[++i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (FAILURE);
	}
	return (SUCCESS);
}

/* does not accept 0 */
static t_bool is_non_zero_int(char *av)
{
	int	i;

	i = -1;
	if (ft_atoi(av) > 2147483647 || ft_atoi(av) < -2147483648 || !ft_atoi(av))
		return (FAILURE);
	while (av[++i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (FAILURE);
	}
	return (SUCCESS);
}

t_bool	check_input(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (FAILURE);
	if (!is_non_zero_int(av[1]) || !is_non_zero_int(av[2])
		|| !is_non_zero_int(av[3]) || !is_non_zero_int(av[4]))
		return (FAILURE);
	if (av[5] && !is_int(av[5]))
		return (FAILURE);
	return (SUCCESS);
}
