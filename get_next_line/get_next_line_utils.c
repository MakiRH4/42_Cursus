/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:35:42 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/19 23:35:42 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_newline(t_gnl_list *gnl_list)
{
	int	i;

	if (!gnl_list)
		return (0);
	while (gnl_list)
	{
		i = 0;
		while (gnl_list->str_buff[i] && i < BUFFER_SIZE)
		{
			if (gnl_list->str_buff[i] == '\n')
				return (1);
			++i;
		}
		gnl_list = gnl_list->link; //wy dis?
	}
	return (0);
}

t_gnl_list	*get_last_node(t_gnl_list *gnl_list)
{
	if (!gnl_list)
		return (NULL);
	while (gnl_list->link)
		gnl_list = gnl_list->link;
	return (gnl_list);
}

void	cp_str(t_gnl_list *gnl_list, char *str)
{
	int	i;
	int	j;

	if (!gnl_list)
		return ;
	j = 0;
	while (gnl_list)
	{
		i = 0;
		while (gnl_list->str_buff[i])
		{
			if (gnl_list->str_buff[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = gnl_list->str_buff[i++];
		}
		gnl_list = gnl_list->link;
	}
	str[j] = '\0';
}

int	len_line(t_gnl_list *gnl_list)
{
	int	i;
	int	len;

	if (!gnl_list)
		return (0);
	len = 0;
	while (gnl_list)
	{
		i = 0;
		while (gnl_list->str_buff[i])
		{
			if (gnl_list->str_buff[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		gnl_list = gnl_list->link;
	}
	return (len);
}

void	free_all(t_gnl_list **gnl_list, t_gnl_list *clean_node, char *buffer)
{
	t_gnl_list	*tmp;

	if (*gnl_list == NULL) // funktionert das auch? (!(*list)) 
		return ;
	while (*gnl_list)
	{
		tmp = (*gnl_list)->link;
		free((*gnl_list)->str_buff);
		free(*gnl_list);
		*gnl_list = tmp;
	}
	*gnl_list = NULL;
	if (clean_node->str_buff[0])
		*gnl_list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}

//

void	polish_list(t_gnl_list **list)
{
	t_gnl_list	*last_node;
	t_gnl_list	*clean_node;
	int			i;
	int			j;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE +1);
	clean_node = malloc(sizeof(t_gnl_list));
	if (!buffer || !clean_node)
		return ;
	last_node = get_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[i] != '\n')
		++i;
	while (last_node->str_buff[i] != '\0' && last_node->str_buff[++i])
		buffer[j++] = last_node->str_buff[i];
	buffer[j] = '\0';
	clean_node->str_buff = buffer;
	clean_node->link = NULL;
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
		while (list -> str_buff[i])
		{
			if (list -> str_buff[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list -> str_buff[i++];
		}
		list = list -> link;
	}
	str[j] = '\0';
}

char	*get_line(t_gnl_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_line(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_string(list, next_str);
	return (next_str);
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
		last_node -> link = new_node;
	new_node -> str_buff = buffer;
	new_node -> link = NULL;
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
		if (!read_length)
		{
			free(buffer);
			return ;
		}
		buffer[read_length] = '\0';
		append(list, buffer);
	}
}
