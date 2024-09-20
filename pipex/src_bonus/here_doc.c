/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:59:08 by fleonte           #+#    #+#             */
/*   Updated: 2024/09/20 12:29:27 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(int argc, char **argv, char **env, int *piped_fds)
{
	char	*line;
	char	*lim;

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
	exeggutor_connex(argc, argv, env, piped_fds);
	return (argc);
}
