/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floris <floris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:18:16 by floris            #+#    #+#             */
/*   Updated: 2023/09/29 21:16:13 by floris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_wordcount, counts how many words are in the intial string, *s
static int ft_wordcount(const char *s, char c)
{
    const char  *str;
    int i;
    int word_end;

    str = s;
    i = 0;
    word_end = 0;
    while (*str++)
    {
        if (*str == c && word_end)
            word_end = 0;
        


    }
}

//ft_wordlength, counts the length of each word and ads an extra char for '\0'
int ft_wordlength(char *s, char c)
{
    int i;

    i = 0;

}
char *ft_wordmalloc()



char    **ft_split(char const *s, char c)
{
    int n_words;


    if (*s)
    {
        n_words = ft_wordcount(s, c);
        ptr = (char *)malloc(sizeof(char) * (n_words + 1));
    }
    else
        return (NULL);
    while(*s)
    {
        ft_wordcount(&s)
    }
}