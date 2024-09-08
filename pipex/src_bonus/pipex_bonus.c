/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 03:37:38 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		piped_fds[2];
	pid_t	*pid;
	int		status;
	int		i_wait;

	if (argc < 5)
		return (ft_printf("%s", "wrong arg count"));
	if (pipe(piped_fds) == -1)
		return (ft_printf("pipe failed"));
	
	pid = exeggutor_connex(argc, argv, env, piped_fds);
/*
	pid[0] = exeggutor_first(ft_verify_command(argv[2], env),
			argv, env, piped_fds);
	pid[1] = exeggutor_last(ft_verify_command(argv[3], env),
			argv, env, piped_fds);
*/
	i_wait = -1;
	while (++i_wait <= argc)
		waitpid(pid[i_wait], &status, 0);
	free(pid);
	return (WEXITSTATUS(status));
}
