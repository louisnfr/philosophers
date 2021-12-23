/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:27:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/24 00:33:02 by lraffin          ###   ########.fr       */
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
# include "struct.h"

# define TAKE_FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[34mis sleeping\e[0m"
# define THINK "\e[35mis thinking\e[0m"
# define DIED "\e[91mdied\e[0m"

/*** init ***/
t_data		*init_data(int ac, char **av);
t_bool		create_philos(t_data *data);
void		join_philos(t_data *data);

/*** parsing ***/
t_bool		check_input(int ac, char **av);

/*** routine ***/
void		*routine(void *arg);
void		eat_action(t_philo *philo, int i);

/*** free ***/
void		clean_data(t_data *data);

/*** utils ***/
void		ft_putstr_fd(int fd, char *s);
long long	ft_atoi(char *s);
/* mutex */
void		write_mutex(t_mutex *mutex, int value);
int			read_mutex(t_mutex *mutex);
/* time*/
int			get_time(void);
void		ft_usleep(int time);
/* print */
void		update_status(char *msg, t_philo *philo, int death);
void		prompt(void);

#endif
