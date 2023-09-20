/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:13:11 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/20 17:21:17 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrimmable(char c, char *sett)
{
	int	i;

	i = 0;
	while (sett[i])
	{
		if (c == sett[i])
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*return_string;
    int i;

	start = (char *)s1;
	end = (char *)s1 + (ft_strlen(s1) - 1);
	while (*start && (ft_istrimmable(*start, (char *)set)))
		*start++ = '\0';
    while (*end && (ft_istrimmable(*end, (char *)set)))
		*end-- = '\0';
	return_string = (char *)malloc(sizeof(char) * (ft_strlen(start) + 1));
	if (!return_string)
		return (NULL);
    i = 0;
    while (*start)
        return_string[i++] = *start++;
	return (return_string);
}
