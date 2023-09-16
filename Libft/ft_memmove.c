/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:21 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/16 18:10:35 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*orig;

	i = 0;
	orig = dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		while (i-- > 0)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	else
	{
		while (dst++ && src++ && i++ <= len)
			*(unsigned char *)dst = *(unsigned char *)src;
	}
	return (orig);
}
