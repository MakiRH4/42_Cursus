/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:59:08 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/12 18:46:27 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(int argc, char **argv, char **env, int *piped_fds)
{
	char	*line;
	char	*lim;
	pid_t	pid;
	char	**new_argv;
	//pid_t	*pid_arr;
	int		i_argv;

	ft_putnbr_fd(argc, 2);
	ft_putstr_fd("\n", 2);
	pid = fork();
	if (pid < 0)
		return(throw_error(1, PHI, PHI));
	else if (pid == 0)
	{
		lim = argv[2];
		close(piped_fds[READ]);

		while (TRUE)
		{
			line = get_next_line(0);
			if (ft_strncmp(line, lim, ft_strlen(lim)) == 0 &&
						ft_strlen(line) == ft_strlen(lim))
				(free(line), close(piped_fds[WRITE]), exit(0));
			(ft_putstr_fd(line, piped_fds[WRITE]), free(line));
		}
		free(lim);
		exit(0); // redundant as it will always shpuld exit on line 32?
	}
// for exeggutor_first, open(piped_fds[WRITE]) or fd == piped_fds[WRITE]
// and argv[1] == piped_fds[WRITE]
// **argv has to be modified prior to calling exeggutor_connex
//	should call exeggutor_connex
	i_argv = 0;
	new_argv = malloc(sizeof(char*) * (argc)); // argc so can add NULL
	new_argv[argc] = NULL;
	while (i_argv < (argc -1))
	{
		ft_putstr_fd("argv:", 2);
		ft_putstr_fd(ft_itoa(i_argv), 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(argv[i_argv], 2);
		ft_putstr_fd("\n", 2);
//		ft_memcpy(argv[i_argv], argv[i_argv + 1], ft_strlen(argv[i_argv + 1])); // but with memcopy
		new_argv[i_argv] = malloc(sizeof(char) * ft_strlen(argv[i_argv + 1]));
		ft_memcpy(new_argv[i_argv], argv[i_argv + 1], ft_strlen(argv[i_argv + 1])); // but with memcopy
		ft_putstr_fd("new_argv:", 2);
		ft_putstr_fd(ft_itoa(i_argv), 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(new_argv[i_argv], 2);
		ft_putstr_fd("\n", 2);
		++i_argv;
	}
	ft_putstr_fd("we made it?", 2);
	ft_putstr_fd("\n", 2);

	exeggutor_connex((argc - 1), new_argv, env, piped_fds);
	return (0);
}
