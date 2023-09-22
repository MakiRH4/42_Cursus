/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim_strigns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:13:11 by fleonte           #+#    #+#             */
/*   Updated: 2023/09/22 14:22:40 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_istrimmable(char c, char *sett)
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
	char	*return_string;
    int i;

	start = s1;
	end = s1 + (strlen(s1) - 1);
	while (*start && ft_istrimmable(*start, (char *)set))
		start++;
    while (end > start&& ft_istrimmable(*end, (char *)set))
		end--;
	printf("start: %s\n", start);
	return_string = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!return_string)
		return (NULL);
    i = 0;
    while (start <= end)
        return_string[i++] = *start++;
	return_string[i] = '\0';
   printf("return_string: %s\n", return_string);
	return (return_string);
}

int	main ()
{
	char *s1 = "1234sdfghgf12345";
	char *trim = "1234567890";
	char *res = ft_strtrim(s1, trim);
	printf("dis is di res boss: %s\n", res);
    return (0);
}