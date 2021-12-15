/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:47:02 by lraffin           #+#    #+#             */
/*   Updated: 2021/12/15 15:47:40 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
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
	if (value > 9223372036854775807 && sign == 1)
		return (-1);
	else if (value > 9223372036854775807 && sign == -1)
		return (0);
	return (value * sign);
}
