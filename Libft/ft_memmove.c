/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:21 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/18 18:16:12 by floris           ###   ########.fr       */
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