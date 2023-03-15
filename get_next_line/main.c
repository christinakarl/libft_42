//#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));

	fd2 = open("text2.txt", O_RDONLY);
	printf("%s", get_next_line(fd2));

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));

	close(fd1);
	close(fd2);

	return (0);
}
