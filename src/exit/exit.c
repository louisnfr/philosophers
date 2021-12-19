/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:36:19 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 02:44:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(char *error_msg, int exit_code)
{
	ft_putstr_fd(2, "error: ");
	ft_putstr_fd(2, error_msg);
	ft_putstr_fd(2, "\n");
	exit(exit_code);
}

void	exit_error_free(t_data *data, char *error_msg, int exit_code)
{
	ft_putstr_fd(2, "error: ");
	ft_putstr_fd(2, error_msg);
	ft_putstr_fd(2, "\n");
	clean_data(data);
	exit(exit_code);
}
