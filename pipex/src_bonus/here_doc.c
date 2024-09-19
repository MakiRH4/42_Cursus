/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:59:08 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/19 21:00:37 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	*exeggutor_connex_hd(int argc, char **argv, char **env, int *piped_fds)
{
	int		i_pid;

	i_pid = 0;
	while (++i_pid + 2 < argc - 2)
		exeggutor_halfway(ft_verify_command(argv[i_pid + 2], env),
				argv, env, piped_fds);
	exeggutor_last(ft_verify_command(argv[argc - 2], env),
			argv[argc - 1], env, piped_fds);
	return (0);
}

int	here_doc(int argc, char **argv, char **env, int *piped_fds)
{
	char	*line;
	char	*lim;
	char	**new_argv;
	int		i;

	lim = argv[2];
	while (TRUE)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0
			&& ft_strlen(line) == (ft_strlen(lim) + 1))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, piped_fds[WRITE]);
		free(line);
	}
	i = 0;
	new_argv = malloc(sizeof(char *) * (argc));
	new_argv[argc -1] = NULL;
	while (i < (argc -1))
	{
		new_argv[i] = malloc(sizeof(char) * ft_strlen(argv[i + 1]));
		new_argv[i][ft_strlen(argv[i + 1])] = 0;
		ft_memcpy(new_argv[i], argv[i + 1], ft_strlen(argv[i + 1]));
		++i;
	}
	exeggutor_connex_hd((argc -1), new_argv, env, piped_fds);
	return (argc);
}
