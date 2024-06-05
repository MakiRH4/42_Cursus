#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	while (*s && *s != '\n')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int gnl2(int fd)
{
    char buffer[BUFFER_SIZE];
    char *text;
    int flag;
    int i;
    int len;
    char **array;

//    if (fd < 0 || BUFFER_SIZE <= 0)
//		  return (NULL);
    read(fd, buffer, BUFFER_SIZE);
    printf("Line 48, buffer:\n%s", buffer);
    printf("\n");
    printf("length is: %d\n", len = strlen(buffer));
    i = 0;
    flag = 0;


    ft_putstr_fd(buffer, 1);
    printf("\n");
    array = ft_split(buffer, '\n');
 /*     
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
  */

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