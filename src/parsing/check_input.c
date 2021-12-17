/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:29 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 23:40:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_input(int ac, char **av)
{
	(void)av;
	if (ac != 5 && ac != 6)
		exit_error("wrong input", EXIT_FAILURE);
	return (SUCCESS);
}