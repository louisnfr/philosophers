/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:51:15 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/19 02:13:05 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(int fd, char *s)
{
	while (s && *s)
		write(fd, s++, 1);
}

long	ft_atoi(char *s)
{
	unsigned long long	value;
	int					sign;
	size_t				i;

	value = 0;
	sign = 1;
	i = 0;
	if (!s)
		return (0);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		value = value * 10 + s[i++] - 48;
	return (value * sign);
}
