/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:20 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 23:05:09 by fleonte          ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

void	free_array(char **array);
int		exeggutor_first(char **command_id,
			char **argv, char **env, int piped_fds[2]);
int		exeggutor_last(char **command_id,
			char **argv, char **env, int piped_fds[2], int argc);
int		exeggutor_halfway(char **command_id, char **argv,
			char **env, int piped_fds[2]);
int		something_failed(int reason, char **argv);
char	*find_path(char *command_id, char **env);
char	*str_in_str(const char *haystack, const char *needle);
char	**ft_verify_command(char *command, char **env);
pid_t	*exeggutor_connex(int argc, char **argv, char **env, int piped_fds[2]);

#endif