/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:27:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/17 18:04:20 by lraffin          ###   ########.fr       */
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

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

/*** init ***/
t_data			*init_data(int ac, char **av);
t_bool			init_philo(t_philo *philo, int i, t_data *data);
t_bool			create_philos(t_data *data);
t_bool			join_philos(t_data *data);

/*** parsing ***/
t_bool			check_input(int ac, char **av);

/*** routine ***/
void			*routine(void *arg);
t_bool			eat_action(t_philo *philo, int i);
void			sleep_action(t_philo *philo);

/*** exit ***/
void			exit_error(char *error_msg, int exit_code);
void			exit_error_free(t_data *data, char *error_msg, int exit_code);
void			clean_data(t_data *data);

/*** utils ***/
void			ft_putstr_fd(int fd, char *s);
int				ft_atoi(char *s);
unsigned long	gettime(void);
void			update_status(char *msg, t_philo *philo);
void			check_death(t_data *data);

#endif
