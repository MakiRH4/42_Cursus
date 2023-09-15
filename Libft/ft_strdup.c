/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:26:40 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/15 22:19:40 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		strtl;

	strl = ft_strlen(s1);
	str = malloc(strl + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, strl);
	str[strl] = '\0';
	return (str);
}
