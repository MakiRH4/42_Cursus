/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:20 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/03 02:15:51 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define FILE1			1	// 1st file
# define COMMAND1		2	// 1st command
# define COMMAND2		3	// 2nd command
# define FILE2			4	// 2nd file
# define READ			0
# define WRITE			1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/wait.h>
# include <fcntl.h>

int		exeggutor(char *command_id, char **argv, char **env, int *piped_fds);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*find_path(char *command_id, char **env);
char	*str_in_str(const char *haystack, const char *needle);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);



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
