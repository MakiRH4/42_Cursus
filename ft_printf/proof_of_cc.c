#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void    ft_put_c(char c);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void    ft_put_c(char c)
{
    ft_putchar_fd(c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int	ft_printf_s(va_list s)
{
	char	*str;

	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_putstr_fd(str, 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

int ft_printf(char const *text, ...)
{
    va_list arguments;
    int i;
    
    i = 0;
    va_start(arguments, text);

    while (text[i] != '\0')
    {
        if(text[i] != '%')
        {
            ft_putchar_fd(text[i], 1);
            ++i;
            continue;
        }
        //i++;
        if(text[++i] == 'c')
        {
            char c = va_arg(arguments, int);
            ft_putchar_fd(c, 1);
            ++i;
        }
        /*else if (text[i] == 'd')
        {
            int d = va_arg(arguments, int);
            ft_putnbr_fd(d, 1);
            ++i;
        }*/
        else if (text[i] == 's')
        {
            char s = va_arg(arguments, int);
            ft_putstr_fd(&s, 1);
            ++i;
            return (ft_printf_s(*s));
        }
        else if (text[i] == 'p')
        {

        }
        else if (text[i] == 'd')
        {
            int d = va_arg(arguments, int);
            ft_putnbr_fd(d, 1);
            ++i;
        }
        else if (text[i] == 'i')
        {

        }
        else if (text[i] == 'u')
        {

        }
        else if (text[i] == 'x')
        {

        }
        else if (text[i] == 'X')
        {

        }
        else if (text[i] == '%')
        {

        }
    }
    va_end(arguments);
}

int main(void)
{
    ft_printf("This is: %c and it's written in: %d and %d and %s", 'c', 12334, 234, "ebec");
    return(0);
}