#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_new_line(char *buffer)
{
  while (buffer)
  {
    if (buffer++ == '\n')
      return (1);
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

int gnl(int fd)
{
    char buffer[BUFFER_SIZE];
    char *text;
    int flag = 0;
    int i;

//    if (fd < 0 || BUFFER_SIZE <= 0)
//		  return (NULL);

    //read(fd, string, BUFFER_SIZE);
    //printf("%s", string);
    //printf("\n");
  i = 0;

      
      printf("\n%s", "buffer");
      text = ft_strjoin(text, buffer);
      //printf("\n%s", text);
      while (flag == 0)
      {
        read(fd, buffer, BUFFER_SIZE);
        if (check_new_line(buffer))
          flag = 1;
        ft_strjoin(text, buffer);
      }
      printf("\n%s", "text");
      printf("\n");
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