/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:49:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/15 22:22:19 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	srcl;
	int	dstl;

	srcl = strlen(src);
	if (!dst && size == 0)
		return (srcl);
	dstl = ft_strlen(dst);
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while (src && dstl++ < dstsize)
		dst++ = src++;
	return (ft_strlen(src) + ft_strlen(dst));
}
