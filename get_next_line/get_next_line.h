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



// saves at the memory address of *str the line that's present in the *list
void		copy_string(t_gnl_list *list, char *str);

// in loop reads from fd as long as no '\n' is read and appends the text read,
// to **list
void		build_list(t_gnl_list **list, int fd);

// in **list, creates a new node and finds the last one, if there is no last
// node, sets the new one as the last one and assings to the last one, the string
void		append(t_gnl_list **list, char *buffer);

// returns a node that contains only the chars read after a '\n' caused by
// the buffer size
void		polish_list(t_gnl_list **list);

// 
void		free_all(t_gnl_list **list, t_gnl_list *clean_node, char *buffer);

// goes through the variables at each node of *gnl:_list searching for a '\n',
// if it finds one returns 1, else returns 0
int			search_newline(t_gnl_list *gnl_list);

// counts the length of the line in *gnl_list moving to the next node until
// a '\n' is found
int			line_length(t_gnl_list *gnl_list);

// returns a pointer to a string that contains the first line of the text
// present in the fd
char		*get_next_line(int fd);

// returns a pointer to the last node of *gnl_list
t_gnl_list	*get_last_node(t_gnl_list *gnl_list);

#endif