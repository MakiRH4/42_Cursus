#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int check_new_line(char *buffer)
{
  while (buffer)
  {
    if (*buffer == '\n')
      return (1);
    buffer++;
  }
  return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*ret;

	if (!s1 || !s2)
		return NULL;
	joined = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
	ret = joined;
	if (!joined)
		return (NULL);
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*(joined) = '\0';
	return (ret);
}
*/
void  create_list(t_list **list, int fd)
{
  int char_read;
  char  *buffer;

  while (!found_newline(*list))
  {
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
      free(buffer);
      return;
    }
    char_read = read(fd, buffer, BUFFER_SIZE);
    if (!char_read);
    {
      free(char_read);
      return;
    }
    buffer[char_read] == '\0';
    append(list, buf);
  }
}

int *get_next_line(int fd)
{
  static t_list *list = NULL;
  char          *next_line;

  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0) // Last one is control to see if file can be accessed
    return (NULL);
  create_list(&list, fd);

  if(!list)
    return (NULL);
  
  next_line = get_line(list);

  polish_list(&list);
  return (next_line);
}
/*
  char buffer[BUFFER_SIZE];
  char *text;
  int flag;
  int i;
  int len;

//    if (fd < 0 || BUFFER_SIZE <= 0)
//		  return (NULL);
//read(fd, buffer, BUFFER_SIZE);
//printf("Line 48, buffer:\n%s", buffer);
//printf("\n");
//printf("length is: %d", len = strlen(buffer));
  i = 0;
  flag = 0;

      
//text = ft_strjoin(text, buffer);
//printf("\nText is:\n%s", text);
  if (flag == 0)
  {
    read(fd, buffer, BUFFER_SIZE);
    if (check_new_line(buffer))
    {  
      flag = 1;
      text = ft_strjoin(text, buffer);
    }
    printf("\n%s", text);
    printf("\n");
    printf("Flag is: %d", flag);
  }  
  return(0);
}
/*
while (end == 0)
{
  while (string[i] < BUFFER_SIZE)
  {
    if (string[i] == "\0")
      {
        end = 1;
        break;
      }
    read(fd, string, BUFFER_SIZE); 
    write(1, &string[i], 1);
    ++i;
  }
}
*/