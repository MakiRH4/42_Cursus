/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:51:02 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/19 13:43:42 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
//	if (*str)
//	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (*str == 45 || *str == 43)
		{
			if (*str == '-')
				sign = -sign;
			str++;
		}
		while (*str >= 48 && *str <= 57)
		{
			res = (res * 10) + *str - 48;
			str++;
		}
//	}
	return (res * sign);
}
