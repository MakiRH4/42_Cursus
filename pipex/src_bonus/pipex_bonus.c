/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:17:04 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/08 23:05:11 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		piped_fds[2];
	pid_t	*pid;
	int		status;
//	int		i_wait;

	if (argc < 5)
		return (ft_printf("%s", "wrong arg count"));
	if (pipe(piped_fds) == -1)
		return (ft_printf("pipe failed"));
	pid = exeggutor_connex(argc, argv, env, piped_fds);
//	i_wait = -1;
/* 	while (++i_wait <= argc - 3)
		waitpid(pid[i_wait], &status, 0);
 */	
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);

free(pid);
	return (WEXITSTATUS(status));
}
