#include <stdio.h>
#include <stdlib.h>

static int ft_intcounter(int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        n = -n;
        i++;
    }
    while (n > 9)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char *number;
    int i;
    
    i = ft_intcounter(n);
    number = malloc(sizeof(char) * (i + 1));
    if (n < 0)
    {
        n = -n;
        number[0] = '-';
    }
    while (n > 9)
    {
        number[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    if (n <= 9)
        number[i] = n + 48;
    return(number);
}

int main()
{
    int n = 10;
    char *resultado = ft_itoa(n);
    printf("el input es: %d", n);
    printf("el output es: %s", resultado);
    return(0);
}