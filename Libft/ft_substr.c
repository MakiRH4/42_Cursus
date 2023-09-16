/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:02:26 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/16 18:04:24 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	i;

	i = 0;
	sbstr = malloc(sizeof(char) * len);
	if (!sbstr)
		return (NULL);
	while (i < len)
	{
		sbstr[i] = s[start];
		i++;
		start++;
	}
	sbstr[len] = '\0';
	return (sbstr);
}
