/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleonte <fleonte@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:35:49 by fleonte           #+#    #+#             */
/*   Updated: 2024/05/19 23:35:49 by fleonte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  polish_list(t_list **list)
{
  t_list  *last_node;
  t_list  *clean node;
  int i;
  int k;
  char *buffer;

  buffer = malloc(BUFFER_SIZE +1);
  clean_node = malloc(sizeof(t_list));
  if (!buffer || !clean_node)
    return;
  last_node = get_last_node(*list);

  i = 0;
  k = 0;
  while (last_node->str_buf[i] != '\0' && last_node->str_buf[i] != '\n')
    ++i;
  while (last_node->str_buf[i] != '\0' && last_node->str_buf[++i])
    buf[k++] = last_node->str_buf[i];
  buf[k] = '\0';
  clean_node->str_buf = buffer;
  clean_node->link = NULL;
  dealloc(list, clean_node, buffer);


}

void  copy_string(t_list *list, char *str)
{
  int i;
  int k;

  if (!list)
    return;
  k = 0;
  while (list)
  {
    i = 0;
    while (list -> str_buf[i])
    {
      if (list -> str_buf[i] == '\n')
      {
        str[k++] = '\n';
        str[k] = '\0';
        return;
      }
      str[k++] = list -> str_buf[i++];
    }
    list = list -> link;
  }
  str[k] = '\0';
}
/*

IN .h !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int len_to_newline(t_list *list)
{
  int i;
  int len;

  if (!list)
    return (0);
  len = 0;
  while (list)
  {
    i = 0;
    while (list -> str_buf[i])
    {
      if (list -> str_buf[i] == '\n')
      {
        ++len;
        return(len);
      }
      ++i;
      ++len;
    }
    list = list -> link;
  }
  return(len);
}
*/
char  *get_line(t_list *list)
{
  int str_len;
  char  *next_str;

  if (!list)
    return (NULL);
  str_len = len_to_newline(list);
  next_str = malloc(str_len + 1);
  if (!next_str)
    return )(NULL);
  copy_string(list, next_str);
  return (next_str);
}

void  append(t_list **list, char *buffer)
{
  t_list  *new_node;
  t_list  *last_node;

  last_node = get_last_node(*list);
  new_node = malloc(sizeof(t_list));
  if (!new_node)
    return;
  if (!last_node)
    *list = new_node;
  else
    last_node -> link = new_node;
  
  new_node -> str_buf = buffer;
  new_node -> link = NULL;
}

void  build_list(t_list **list, int fd)
{
	int	read_length;
	char	*buffer;

	while (!search_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(buffer);
			return;
		}
		read_length = read(fd, buffer, BUFFER_SIZE);
		if (!read_length);
		{
			free(read_length);
			return;
		}
		buffer[read_length] == '\0';
		append(list, buffer);
	}
}

int *get_next_line(int fd)
{
	static	t_gnl_list	*list;	//variable deklarieren, list
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0) //Der korrekte Zugriff auf die Datei wird geprüft
		return (NULL);
	*list = NULL;	//Variable initialisieren

	build_list(&list, fd);
	if(!list)
		return (NULL);
	
	next_line = get_line(list);

	polish_list(&list);

	return (next_line);
}
