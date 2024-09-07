/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 00:06:48 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		piped_fds[2];
	pid_t	pid[2];
	int		status;

	if (argc < 5)
		return (ft_printf("%s", "wrong arg count"));
	if (pipe(piped_fds) == -1)
		return (ft_printf("pipe failed"));
	
	exeggutor_connex(argc, argv, env, piped_fds);
/*
	pid[0] = exeggutor_first(ft_verify_command(argv[2], env),
			argv, env, piped_fds);
	pid[1] = exeggutor_second(ft_verify_command(argv[3], env),
			argv, env, piped_fds);
*/
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
