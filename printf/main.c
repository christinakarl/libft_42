#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%s asdf %d\n\n", "hallo", 56);
	printf("%s asdf %d\n", "hallo", 56);
	return (0);
}
