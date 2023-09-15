/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:24:21 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/15 22:24:05 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*orig;

	i = 0;
	orig = dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = n - 1;
		while (i-- > 0)
			dst-- = src--;
	}
	else
	{
		while (dst++ && src++ && i++ <= len)
			dst = src;
	}
	return (orig);
}
