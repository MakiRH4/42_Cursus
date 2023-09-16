/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:49:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/16 19:07:48 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	dstl;

	srcl = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (srcl);
	dstl = ft_strlen(dst);
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while (src && dstl++ < dstsize)
		*dst++ = *src++;
	return (ft_strlen(src) + ft_strlen(dst));
}
