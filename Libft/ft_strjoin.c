/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:03:05 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/18 02:49:09 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		ttl;

	ttl = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(s1) + sizeof(s2) + 1);
	if (!joined)
		return (NULL);
	while (*s2)
	{
		while (*s1)
			*joined++ = *s1++;
		*joined++ = *s2++;
	}
	*(++joined) = '\0';
	return (joined - (ttl + 1));
}
