#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 0;
    while (i++ <= 5)
    {
        if (i >= 0)
        {
            printf("%d", i);
           // continue;
        }
        printf("mahia");
    }
    return (0);
}