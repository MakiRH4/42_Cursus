/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:16 by floris            #+#    #+#             */
/*   Updated: 2023/10/04 00:10:58 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
	length = strlen(copy_of_s);
	while (i <= length)
	{
		if (copy_of_s[i] == c)
			copy_of_s[i] = '\0';
		++i;
	}
}

static int	ft_malloc_word(char **array, int i, int word_length, char **copy_of_s)
{
	int	copied_word;

	array[i] = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!array[i])
	{
		copied_word = 0;
		while (copied_word <= i)
			free(array[copied_word++]);
		free(array);
		free(copy_of_s);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	*copy_of_s;
	char	**array;
	int		number_of_words;
	int		word_length;
	int			i;

	i = 0;
	copy_of_s = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	if (!copy_of_s)
		return (0);
	memcpy(copy_of_s, s, (strlen(s) + 1));
	number_of_words = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if (!array)
<<<<<<< Updated upstream
=======
	{
		free(array);
>>>>>>> Stashed changes
		return (0);
	ft_strprep(copy_of_s, c);
	while (i < number_of_words)
	{
		while (*copy_of_s == '\0')
			copy_of_s++;
		word_length = strlen(copy_of_s);
		if (!ft_malloc_word(array, i, word_length, &copy_of_s))
			return (0);
		memcpy(array[i], copy_of_s, word_length);
		array[i++][word_length] = '\0';
		copy_of_s += word_length;
		while (*copy_of_s == '\0' && i < number_of_words)
			++copy_of_s;
	}
	array[i] = 0;
	return (array);
}