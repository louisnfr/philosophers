/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:27:28 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/18 01:31:45 by lraffin          ###   ########.fr       */
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

# define TAKE_FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[34mis sleeping\e[0m"
# define THINK "\e[35mis thinking\e[0m"
# define DIED "\e[91mdied\e[0m"

/*** init ***/
t_data	*init_data(int ac, char **av);
t_bool	create_philos(t_data *data);
void	join_philos(t_data *data);

/*** parsing ***/
t_bool	check_input(int ac, char **av);

/*** routine ***/
void	is_dead(t_philo *philo);
void	is_all_fed(t_data *data);
void	*routine(void *arg);
t_bool	eat_action(t_philo *philo, int i);
void	sleep_action(t_philo *philo);
void	think_action(t_philo *philo);

/*** exit ***/
void	exit_error(char *error_msg, int exit_code);
void	exit_error_free(t_data *data, char *error_msg, int exit_code);
void	clean_data(t_data *data);

/*** utils ***/
void	ft_putstr_fd(int fd, char *s);
int		ft_atoi(char *s);
long	get_time(void);
void	ft_usleep(long time);
void	update_status(char *msg, t_philo *philo);
void	prompt(void);

#endif
