/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:51:02 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/14 18:27:50 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int ft_atoi(const char *str)
{
    int	sign;
	int	res;
    int signcount;

	sign = 1;
    signcount = 0;
	res = 0;
	if (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (*str == 45)
        {
			sign = -sign;
            signcount++;
            if (signcount > 1)
                return (0);
        	str++;
		}
		if (*str == 43)
        {
			sign = -sign;
            signcount++;
            if (signcount > 1)
                return (0);
        	str++;
		}
		while (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + *str - 48;
			str++;
		}
	}
	return (res * sign);
}