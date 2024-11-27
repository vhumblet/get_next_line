#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (i != 8)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
