/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/26 18:08:05 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		piped_fds[2];
	int		status;
	int		i_wait;
	pid_t	pid;

	pid = 0;
	status = 0;
	if (argc < 5)
		return (ft_putstr_fd("pipex: argc error\n", 2), -1);
	if (pipe(piped_fds) == -1)
		return (ft_printf("main pipe failed"), -1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc > 5)
		argc = here_doc(argc, argv, env, piped_fds);
	else
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			return (throw_error(4, NULL, piped_fds));
		else
			pid = exeggutor_connex(argc, argv, env, piped_fds);
	}
	i_wait = -1;
	while (++i_wait <= argc - 3)
		waitpid(pid, &status, 0);
	return (pid);
}
