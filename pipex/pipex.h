/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:20 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/05 02:17:33 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ			0
# define WRITE			1
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "Libft/libft.h"

void	free_array(char **array);
char **ft_verify_command(char *command, char **env);
int		exeggutor(char **command_id, char **argv, char **env, int *piped_fds);
int		exeggutor2(char **command_id, char **argv, char **env, int *piped_fds);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*find_path(char *command_id, char **env);
char	*str_in_str(const char *haystack, const char *needle);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);


#endif