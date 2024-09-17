/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:59:08 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/17 05:24:40 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	exeggutor_first_hd(char **command_id, char **env, int piped_fds[2])
{
	pid_t	pid;
	int		status;

	status = 0;
	if (command_id == NULL)
		return(throw_error(3, PHI, PHI), 0);
	pid = fork();
	if (pid < 0)
		return (throw_error(1, NULL, PHI), exit(1), -1);
	else if (pid == 0)
	{
		dup2(piped_fds[READ], STDIN_FILENO);
		close(piped_fds[READ]);
		dup2(piped_fds[WRITE], STDOUT_FILENO);
		close(piped_fds[WRITE]);
		if ((execve(command_id[0], command_id, env)) == -1)
			(throw_error(3, command_id[0], PHI), exit(127));
		exit(0);	
	}
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 12)
		return(-1);
	free_array(command_id);
	return (pid);
}

pid_t	*exeggutor_connex_hd(int argc, char **argv, char **env, int piped_fds[2])
{
	pid_t	*pid;
	int		i_pid;

	i_pid = 0;
	pid = malloc(sizeof(pid_t) * (argc - 2));
	pid[i_pid] = exeggutor_first_hd(ft_verify_command(argv[i_pid + 2], env),
			env, piped_fds);
	if (pid[i_pid] == -1)
		return (free(pid), NULL);
	while (++i_pid + 2 < argc - 2)
	{
		pid[i_pid] = exeggutor_halfway(ft_verify_command(argv[i_pid + 2], env),
				argv, env, piped_fds);
		if (pid[i_pid] == -1)
			return (free(pid), NULL);
	}
	pid[i_pid] = exeggutor_last(ft_verify_command(argv[argc - 2], env),
			argv[argc - 1], env, piped_fds);
	if (pid[i_pid] == -1)
		return (free(pid), NULL);
	return (pid);
}


int	here_doc(int argc, char **argv, char **env, int *piped_fds)
{
	char	*line;
	char	*lim;
//	pid_t	pid;
	char	**new_argv;
	int		i_argv;
//	int		status;

//	pid = fork();
//	if (pid < 0)
//		return(throw_error(1, PHI, PHI));
//	else if (pid == 0)
//	{
	lim = argv[2];
//	close(piped_fds[READ]);
	while (TRUE)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0 &&
					ft_strlen(line) == (ft_strlen(lim) + 1))
		{
			free(line);
			break;
		}
		ft_putstr_fd(line, piped_fds[WRITE]);
		free(line);
	}
		//exit(0);
//	}
//	elsed
//		waitpid(-1, &status, 0);
	i_argv = 0;
	new_argv = malloc(sizeof(char *) * (argc - 2)); // argc so can add NULL
	while (i_argv < (argc -1))
	{
		new_argv[i_argv] = malloc(sizeof(char) * ft_strlen(argv[i_argv + 2]));
		new_argv[i_argv][ft_strlen(argv[i_argv + 2])] = 0;
		ft_memcpy(new_argv[i_argv], argv[i_argv + 2], ft_strlen(argv[i_argv + 2])); // but with memcopy
		++i_argv;
	}
	exeggutor_connex_hd((argc - 1), new_argv, env, piped_fds);
	return (argc);
}
