/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:42:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/16 01:55:44 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	ft_putstr_fd(int fd, char *s);
int		ft_atoi(char *s);

unsigned long	gettime(void);

void	update_status(char *msg, t_philo *philo);

#endif
