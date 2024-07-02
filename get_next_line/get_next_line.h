/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:35:52 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/19 23:35:52 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct gnl_list
{
	char			*string_buffer;
	struct gnl_list	*link;
}				t_gnl_list;

void	cp_str(t_gnl_list *gnl_list, char *str);
void	free_all(t_gnl_list **list, t_gnl_list *clean_node, char *buffer);
int		len_line(t_gnl_list *gnl_list);
int		search_newline(t_gnl_list *gnl_list);
char	*get_next_line(int fd);
t_gnl_list	*get_last_node(t_gnl_list *gnl_list);

#endif