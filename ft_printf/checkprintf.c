#include "ft_printf.h"

int main(void)
{
    char c = 'c';
    char *s = "stringgggg";
    void *p = (char *)s;
    int d = 012;
    int x = 765432;
    int X = 123;
    char symbol = '%';
    int ft_printf_len;
    int printf_len;
    ft_printf_len = ft_printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf("ft_printf-länge ist: %d chars\n", ft_printf_len);
    printf("Adresse des Zeigers: %p\n", (void *)&d);
    printf_len = printf("Das ist: %c und es schreibt:\nd: %d\nx: %x\nX: %X\ns: %s\nund Zeiger: %p\nund der neueste freund: %%\n", 'C', d, x, X, s, (void *)&d);
    printf ("printf-länge ist: %d chars\n", printf_len);
    /*
    ft_printf_len = ft_printf("\n%p", (void *)&d);
    printf_len = printf("\n%p", (void *)&d);
    */
    //ft_printf_len = ft_printf("\n%p", s);
    //printf_len = printf("\n%p", s);
    printf("\n%d vs %d", ft_printf_len, printf_len);
    return(0);
}
