/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:13:11 by fleonte           #+#    #+#             */
/*   Updated: 2024/10/21 17:53:28 by fleonte          ###   ########.fr       */
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
	const char	*start;
	const char	*end;
	char		*return_string;
	int			i;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + (ft_strlen(s1) - 1);
	while (*start && ft_istrimmable(*start, (char *)set))
		start++;
	while (end > start && ft_istrimmable(*end, (char *)set))
		end--;
	return_string = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!return_string)
		return (NULL);
	i = 0;
	while (start <= end)
		return_string[i++] = *start++;
	return_string[i] = '\0';
	return (return_string);
}
