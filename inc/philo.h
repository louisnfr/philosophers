/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:27:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 01:55:51 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# include "enum.h"
# include "struct.h"
# include "utils.h"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

t_dinner	*init_dinner(int ac, char **av);
t_bool		create_philos(t_dinner *data);
t_bool		join_philos(t_dinner *data);

void		*routine(void *arg);

void	exit_error(char *error_msg, int exit_code);
void	exit_error_free(t_dinner *dinner, char *error_msg, int exit_code);

#endif
