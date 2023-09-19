/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:35:03 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/18 19:29:43 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && (i + j) < len)
		{
			if (haystack[i + j] && needle[j])
				return ((char *)(haystack + i));
			j++;
		}
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
