#include <stdint.h>

int printf_p(void *p)
{
    int ret1;
    int ret2;

    if (p == NULL)
        return (ft_putstr_fd("0x0", 1));
    ret1 = ft_putstr_fd("0x", 1);
//    if (ret1 == -1)
//        return (-1);
    ret2 = printf_x((uintptr_t)p);
//    if (ret2 == -1)
//        return (-1);
    return (ret1 + ret2);
}