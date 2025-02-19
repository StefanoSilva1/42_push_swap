/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:26:16 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/02/19 07:20:53 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	check_overflow(long result, long prev, int sign)
{
	if (result / 10 != prev)
	{
		if (sign == 1)
			return (2147483647);
		return (-2147483648);
	}
	return (result);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;
	long	prev;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = result;
		result = result * 10 + (str[i] - '0');
		result = check_overflow(result, prev, sign);
		i++;
	}
	return (result * sign);
}
