/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:49:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/13 19:47:08 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Appends src to string dst of size dstsize (unlike strncat, dstsize is the
 * full size of dst, not space left).  At most dstsize-1 characters
 * will be copied.  Always NUL terminates (unless dstsize <= strlen(dst)).
 * Returns strlen(initial dst) + strlen(src); if retval >= siz,
 * truncation occurred.
 */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    int srcl;
    int dstl;

    srcl = strlen(src);
	if (!dst && size == 0)
    {

        return (srcl);
    }    
    dstl = ft_strlen(dst);
    if (dstsize <= dstl)
        return (dstsize + srcl);
    while (src && dstl++ < dstsize)
        dst++ = src++;
    return (ft_strlen(src) + ft_strlen(dst));
}