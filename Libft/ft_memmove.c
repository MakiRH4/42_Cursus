/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:21 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/17 23:34:27 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (!dst && !src)
		return (NULL);
	if (dst == src || len == 0)
		return (dst);
	if (dst > src && (int*)dst - (int*)src < (int)len)
	{
		i = len - 1;
		while (i-- > 0)
			*(unsigned char *)(dst + 1) = *(unsigned char *)(src + 1);
	}
	if (src > dst && (int*)src - (int*)dst < (int)len)
	{
		i = 0;
		while (i++ < len)
			*(unsigned char *)dst = *(unsigned char *)src;
	}
	ft_memcpy(dst, src, len);
	return (dst);
}