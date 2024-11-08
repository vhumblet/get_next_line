/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet <vhumblet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:22:53 by vhumblet          #+#    #+#             */
/*   Updated: 2024/11/08 12:52:19 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	feel_free(char **ptr)
{
	if (!*ptr || !ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static char	*dup_free_line(char *str)
{
	char	*line;

	line = ft_strdup(str);
	if (!line)
		feel_free(&line);
	feel_free(&str);
	return (line);
}

static char	*read_and_store(int fd, char *buffer, char *rest)
{
	int		bytes_read;
	char	*str_tmp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!rest)
			rest = ft_strdup("");
		str_tmp = rest;
		rest = ft_strjoin(str_tmp, buffer);
		feel_free(&str_tmp);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (rest);
}

static char	*sep_line_from_rest(char *line)
{
	size_t	count;
	char	*rest;

	count = 0;
	if (!line)
		return (NULL);
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	rest = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!rest || *rest == '\0')
		feel_free(&rest);
	line[count + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_and_store(fd, buffer, rest);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		feel_free(&line);
		feel_free(&rest);
		return (NULL);
	}
	rest = sep_line_from_rest(line);
	line = dup_free_line(line);
	return (line);
}
