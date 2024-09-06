/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:21 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/19 15:42:59 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;

	if (!dst && !src)
		return (0);
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		i = (int)len;
		while (--i >= 0)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	return (dst);
}
