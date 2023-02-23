#include "gnl.h"

int	main(void)
{
	int		fd;
	char	*getline;

/*1. call*/	fd = open("text.txt", O_RDONLY);
			getline = get_next_line(fd);
			printf("%s\n", getline);
			//free(getline);

/*2. call	getline = get_next_line(fd);
			printf("%s\n", getline);
			free(gnl);
3. call	getline = get_next_line(fd);
			printf("%s\n", getline);*/
//			free(gnl);
	//printf("%d\n", fd);
	close(fd);
	return (0);
}