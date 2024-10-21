/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:16 by floris            #+#    #+#             */
/*   Updated: 2024/10/21 17:52:14 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	number_of_words;

	i = 0;
	number_of_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++number_of_words;
		++i;
	}
	return (number_of_words);
}

static void	ft_strprep(char *copy_of_s, char c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(copy_of_s);
	while (i <= length)
	{
		if (copy_of_s[i] == c)
			copy_of_s[i] = '\0';
		++i;
	}
}

static int	ft_dup_word(char **array, int i, char *copy_of_s)
{
	int	copied_word;

	array[i] = ft_strdup(copy_of_s);
	if (!array[i])
	{
		copied_word = 0;
		while (copied_word <= i)
			free(array[copied_word++]);
		free(array);
		return (0);
	}
	return (1);
}

static char	**ft_array_forming(char **array,
						int number_of_words, char *copy_of_s)
{
	char	*free_pointer;
	int		i;

	i = 0;
	free_pointer = copy_of_s;
	while (i < number_of_words)
	{
		while (*copy_of_s == '\0')
			copy_of_s++;
		if (!ft_dup_word(array, i++, copy_of_s))
		{
			copy_of_s = free_pointer;
			free(copy_of_s);
			return (NULL);
		}
		copy_of_s += ft_strlen(copy_of_s);
		while (*copy_of_s == '\0' && i < number_of_words)
			++copy_of_s;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	*copy_of_s;
	char	*free_pointer;
	char	**array;
	int		number_of_words;

	if (!s)
		return (NULL);
	copy_of_s = ft_strdup(s);
	if (!copy_of_s)
		return (0);
	free_pointer = copy_of_s;
	number_of_words = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if (!array)
	{
		free(copy_of_s);
		return (0);
	}
	ft_strprep(copy_of_s, c);
	if (!ft_array_forming(array, number_of_words, copy_of_s))
		return (0);
	copy_of_s = free_pointer;
	free(copy_of_s);
	return (array);
}
