#include "get_next_line.h"

int	main(void)
{
	int		fd;

/*1. call*/	fd = open("text.txt", O_RDONLY);
			printf("%s", get_next_line(fd));
			//free(getline);

/*2. call*/	printf("%s", get_next_line(fd));

/*3. call*/	printf("%s", get_next_line(fd));
			
		//	printf("%s\n", get_next_line(fd));

		//	printf("%s\n", get_next_line(fd));

//			free(gnl);
	//printf("%d\n", fd);
	close(fd);
	return (0);
}
