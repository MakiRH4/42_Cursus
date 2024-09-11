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
	char			*str_buff;
	struct gnl_list	*link;
}				t_gnl_list;

void		copy_string(t_gnl_list *list, char *str);
void		build_list(t_gnl_list **list, int fd);
void		append(t_gnl_list **list, char *buffer);
void		polish_list(t_gnl_list **list);
void		free_all(t_gnl_list **list, t_gnl_list *clean_node, char *buffer);
int			search_newline(t_gnl_list *gnl_list);
int			line_length(t_gnl_list *gnl_list);
char		*get_next_line(int fd);
t_gnl_list	*get_last_node(t_gnl_list *gnl_list);

#endif