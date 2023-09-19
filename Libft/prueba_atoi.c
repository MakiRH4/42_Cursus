#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int n = atoi(argv[1]);
	printf("atoi says: %d\n", n);
	int m = ft_atoi(argv[1]);
	printf("ft_atoi says: %d\n", m);
}
