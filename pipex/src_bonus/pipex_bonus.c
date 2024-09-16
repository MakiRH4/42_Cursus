/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/17 00:52:52 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		piped_fds[2];
	pid_t	*pid;
	int		status;
	int		i_wait;

	status = 0;
	pid = NULL;
	if (argc < 5)
		return (-1);
	if (pipe(piped_fds) == -1)
		return (ft_printf("pipe failed"), -1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc > 5)
		argc = here_doc(argc, argv, env, piped_fds);
	else
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			return(throw_error(4, PHI, piped_fds));
		else
			pid = exeggutor_connex(argc, argv, env, piped_fds);
	}
	i_wait = -1;
	while (++i_wait <= argc - 3)
		waitpid(-1, &status, 0);
	free(pid);
	return (WEXITSTATUS(status));
}
