/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:42:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 15:54:19 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strlen(char *s);
void	ft_putstr_fd(int fd, char *s);
void	exit_error(char *error_msg, int exit_code);

#endif
