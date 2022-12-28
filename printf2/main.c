#include <stdio.h>

int	ft_printf(const char *print, ...);

int	main(void)
{
	char c;
	char	*ptr;

	c = 66;
	ptr = &c;
	ft_printf("%c%s %d %X %p %u\n", c, "raten", 654, 432, ptr, 4294967294);
	printf("%c%s %d %x %p %u\n", c, "raten", 654, 432, ptr, 4294967294);
	return (0);
}
