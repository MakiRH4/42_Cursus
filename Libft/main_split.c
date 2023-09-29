/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:16 by floris            #+#    #+#             */
/*   Updated: 2023/09/30 01:18:38 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//ft_wordcount, counts how many words are in the intial string, *s
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
//ft_strprep, prepares the string, replacing the separating char c with \0
static void ft_strprep(char *copy_of_s, char c)
{
    int i;
    int length;

    i = 0;
    length = strlen(copy_of_s);
    while (i <= length)
    {
        if (copy_of_s[i] == c)
            copy_of_s[i] = '\0';
    ++i;
    }
}


char    **ft_split(char const *s, char c)
{
    char    *copy_of_s;
    char **array;
    int number_of_words;
    int word_length;
    int i;

    i = 0;
//    if (s)
//    {
        copy_of_s = (char *)malloc(sizeof(char) * (strlen(s) + 1)); //malloc to copy s
        memcpy(copy_of_s, s, (strlen(s) + 1)); //memcopy of s to copy_of_s
//    }
    number_of_words = ft_wordcount(s, c);
    array = (char **)malloc(sizeof(char *) * (number_of_words + 1));
    if (!array)
        return (NULL);
    ft_strprep(copy_of_s, c);
    while(i <= number_of_words)
    {
        word_length = strlen(copy_of_s);
        array[i] = (char *)malloc(sizeof(char) * (word_length + 1));
        memcpy(array[i], copy_of_s, word_length);
        copy_of_s += word_length;
//        while (*copy_of_s == '\0')
//            ++copy_of_s;
        ++i;
    }
    return (array);
}

int main(int argc, char **argv)
{
    (void)argc;
    ft_split(argv[1], *argv[2]);
    return (0);
}