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
		while (gnl_list->string_buffer[i] && i < BUFFER_SIZE)
		{
			if (gnl_list->string_buffer[i] == '\n')
				return (1);
			++i;
		}
//		gnl_list = gnl_list->link; //wy dis?
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
		return;
	j = 0;
	while (gnl_list)
	{
		i = 0;
		while (gnl_list->string_buffer[i])
		{
			if (gnl_list->string_buffer[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return;
			}
			str[k++] = gnl_list->string_buffer[i++];
		}
		gnl_list = gnl_list->link;
	}
	str[k] = '\0';
}

int	len_line(t_gnl_list gnl_list)
{
	int	i;
	int	len;

	if (!gnl_list)
		return (0);
	len = 0;
	while (gnl_list)
	{
		i = 0;
		while (gnl_list->string_buffer[i])
		{
			if (gnl_list->string_buffer[i] == '\n')
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

void	free_all(t_gnl_list **list, t_gnl_list *clean_node, char *buffer)
{
	t_gnl_list *tmp;

	if (*gnl_list == NULL) // funktionert das auch? (!(*list)) 
		return;
	while (*gnl_list)
	{
		tmp = (*gnl_list)->link;
		free((*gnl_list)->string_buffer);
		free(*gnl_list);
		*gnl_list = tmp;
	}
	*gnl_list = NULL;
	if (clean_node->string_buffer[0])
		*gnl_list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}