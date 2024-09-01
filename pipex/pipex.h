/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:20 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/01 02:02:05 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*find_path(char *command_id, char **env);
char	*str_in_str(const char *haystack, const char *needle);
size_t	ft_strlen(const char *s);
int		pipex(char **command_id, char **argv, char **env);
void	*ft_memcpy(void *dst, const void *src, size_t n);



/*
typedef struct s_printer
{
	va_list	arguments;
	int		width;
	int		length;
	int		count;
}			t_printer;

int	ft_printf(char const *text, ...);
int	printf_c(int c);
int	printf_p(char *pointer);
int	printf_x(unsigned long number, char *base);
int	printf_s(char *str);
int	printf_d_i(int number);
int	printf_u(unsigned int number);
*/


#endif
