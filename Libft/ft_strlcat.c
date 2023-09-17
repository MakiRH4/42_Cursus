/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:49:13 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/18 00:46:15 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	srcl;
	unsigned int	dstl;

	dstsize = (unsigned int)dstsize;
	srcl = strlen(src);
	if (!dst && dstsize == 0)
		return (srcl);
	dstl = strlen(dst);
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while (*src && ++dstl < dstsize - 1)
		*dst++ = *src++;
	*dst = '\0';
	printf("res src: %s\n", src);
	printf("res dst: %s\n", dst);
	return (strlen(src) + strlen(dst));
}
/*****************/



int	main(int argc, char **argv)
{
	(void)argc;
	char *src = argv[1];
	char *dst = argv[2];
	int dstsize = atoi(argv[3]);
	int	res;

	printf("untouched src: %s\n", src);
	printf("untouched dst: %s\n", dst);
	printf("untouched dstsize: %d\n", dstsize);

	
	res = ft_strlcat(src, dst, dstsize);
	printf("res is: %d\n", res);
	return (0);
}