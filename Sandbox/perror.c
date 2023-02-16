
#include <stdio.h>
//#include <errno.h>
# include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int	main()
{
	char	*str;

	open("wrong_file", O_RDONLY);
	printf("%s\n", strerror(errno));
	perror("ERROR open");
	printf("continue...\n");
	exit(EXIT_SUCCESS);
	printf("further continue...\n");
	return (0);
}