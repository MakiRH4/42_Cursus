/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:35:49 by fleonte           #+#    #+#             */
/*   Updated: 2024/08/27 02:18:16 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	polish_list(t_gnl_list **list)
{
	t_gnl_list	*last_node;
	t_gnl_list	*clean_node;
	int			i;
	int			j;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return ;
	clean_node = malloc(sizeof(t_gnl_list));
	if (!clean_node)
	{
		free(buffer);
		return ;
	}
	last_node = get_last_node(*list);
	j = ((i = 0), 0);
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[++i])
		buffer[j++] = last_node->str_buff[i];
	clean_node->str_buff = ((clean_node->link = 0), (buffer[j] = 0), buffer);
	free_all(list, clean_node, buffer);
}

void	copy_string(t_gnl_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i])
		{
			if (list->str_buff[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buff[i++];
		}
		list = list->link;
	}
	str[j] = '\0';
}

void	append(t_gnl_list **list, char *buffer)
{
	t_gnl_list	*new_node;
	t_gnl_list	*last_node;

	last_node = get_last_node(*list);
	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->link = new_node;
	new_node->str_buff = buffer;
	new_node->link = NULL;
}

void	build_list(t_gnl_list **list, int fd)
{
	int		read_length;
	char	*buffer;

	while (!search_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(buffer);
			return ;
		}
		read_length = read(fd, buffer, BUFFER_SIZE);
		if (!read_length || read_length < 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_length] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list;
	int					line_len;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	build_list(&list, fd);
	if (!list)
		return (NULL);
	line_len = line_length(list);
	next_line = malloc(line_len + 1);
	if (!next_line)
		return (NULL);
	copy_string(list, next_line);
	polish_list(&list);
	return (next_line);
}
