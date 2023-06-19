#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", i);
	exit(0);
	return (0);
}
