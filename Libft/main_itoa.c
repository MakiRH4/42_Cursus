#include <stdio.h>

char *ft_itoa(int n)
{
    char *number;
//    char *start;

//   *number = '0';
//    start = number;

    if (n > 9)
    {
        number[i++] = (n % 10) + 48;
        ft_itoa(n/10);

    }
    number[i++] = n + 48;
    number = '\0';
    return(number - 5);
}

int main()
{
    int n = 12345678;
    char *resultado = ft_itoa(n);
    printf("el input es: %d", n);
    printf("el output es: %s", resultado);
    return(0);
}