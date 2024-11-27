#include "get_next_line.h"

void	feel_free(char **ptr)
{
	if (*ptr && ptr)
	{
		free(*ptr);
	}
	*ptr = NULL;
}

static char	*get_dup_line(char *line)
{
	if (line)
	{
		line = ft_strdup(line, 1);
		if (!line)
			return (NULL);
		return (line);
	}
	return (NULL);
}

static char	*sep_line_from_rest(char **line, char *rest)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(*line);
	if (len == 0)
		return (NULL);
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if (len == i)
		return (NULL);
	rest = ft_substr(line, i + 1, len - i);
	if (!rest)
	{
		if (!*line || !ft_strlen(*line))
			feel_free(line);
		return (NULL);
	}
	(*line)[i + 1] = '\0';
	return (rest);

}

static char	*read_and_store(int fd, char *buffer, char **rest)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		*rest = ft_strjoin(rest, buffer);
		if (!*rest)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (!*rest)
		return (NULL);
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char			*line;
	static char		*rest = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (feel_free(&rest), NULL);
	line = read_and_store(fd, buffer, &rest);
	if (!line)
		return (NULL);
	rest = sep_line_from_rest(&line, rest);
	if (!line)
		return (NULL);
	//printf("%s\n", line);
	line = get_dup_line(line);
	//printf("%s\n", line);
	if (!line)
		return (feel_free(&rest), NULL);
	return (line);
}
