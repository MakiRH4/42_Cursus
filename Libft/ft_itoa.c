/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:18 by floris            #+#    #+#             */
/*   Updated: 2023/09/24 17:45:04 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intcounter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_intcounter(n) + 1;
	number = malloc(sizeof(char) * (i + 1));
	if (!number)
		return (NULL);
	number[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
	}
	while (n > 9)
	{
		number[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	if (n <= 9)
		number[i] = n + 48;
	return (number);
}
